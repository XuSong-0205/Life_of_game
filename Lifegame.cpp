#include"Lifegame.h"

Lifegame::Lifegame(int s) :mapSize(s)
{
	lifeMap.resize(mapSize);									// 设置列的大小
	default_random_engine random(time(nullptr) & 0xffffffff);
	const uniform_int_distribution<int> range(0, static_cast<int>(1 / PROBABILITY));
	for (int i = 0; i < mapSize; i++)
	{
		lifeMap.at(i).resize(mapSize);							// 设置行的大小
		for (int j = 0; j < mapSize; j++)
		{
			lifeMap.at(i).at(j) = static_cast<int>(range(random) * PROBABILITY);	// 随机取0 or 1   概率由PROBABILITY决定
		}
	}
}

Lifegame& Lifegame::onlyObject()noexcept
{
	static Lifegame lifegame;
	return lifegame;
}

void Lifegame::play()
{
	life();
	draw();
}

void Lifegame::life()
{
	const vector<vector<int>> dir{ {-1,-1},{-1,0},{-1,1},
	{0,-1},{0,1},{1,-1},{1,0},{1,1} };
	for (int i = 0; i < mapSize; ++i)
	{
		for (int j = 0; j < mapSize; ++j)
		{
			int nums = 0;									// 周围细胞数量
			for (int k = 0; k < 8; ++k)
			{
				const int y = i + dir.at(k).at(0);
				const int x = j + dir.at(k).at(1);
				nums += (y < 0 || y >= mapSize || x < 0 || x >= mapSize ? 0 : lifeMap.at(y).at(x) & 1);
			}
			
			if (nums == 2)									// 状态不变
				lifeMap.at(i).at(j) |= (lifeMap.at(i).at(j) & 1) << 1;
			else if (nums == 3)								// 为生
				lifeMap.at(i).at(j) |= 2;
		}
	}

	for (auto& y : lifeMap)									// 更新细胞状态
		for (auto& x : y)
			x >>= 1;
}

void Lifegame::draw()const
{
	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			if (lifeMap.at(i).at(j))										// 当前状态是否存活
																			// 画边长为WDITH的矩形
				solidrectangle(i * WIDTH, j * WIDTH, i * WIDTH + WIDTH - 1, j * WIDTH + WIDTH - 1);	
		}
	}
}