#include"Lifegame.h"

Lifegame::Lifegame(int s) :mapSize(s)
{
	lifeMap.resize(mapSize);									// �����еĴ�С
	default_random_engine random(time(nullptr) & 0xffffffff);
	const uniform_int_distribution<int> range(0, static_cast<int>(1 / PROBABILITY));
	for (int i = 0; i < mapSize; i++)
	{
		lifeMap.at(i).resize(mapSize);							// �����еĴ�С
		for (int j = 0; j < mapSize; j++)
		{
			lifeMap.at(i).at(j) = static_cast<int>(range(random) * PROBABILITY);	// ���ȡ0 or 1   ������PROBABILITY����
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
			int nums = 0;									// ��Χϸ������
			for (int k = 0; k < 8; ++k)
			{
				const int y = i + dir.at(k).at(0);
				const int x = j + dir.at(k).at(1);
				nums += (y < 0 || y >= mapSize || x < 0 || x >= mapSize ? 0 : lifeMap.at(y).at(x) & 1);
			}
			
			if (nums == 2)									// ״̬����
				lifeMap.at(i).at(j) |= (lifeMap.at(i).at(j) & 1) << 1;
			else if (nums == 3)								// Ϊ��
				lifeMap.at(i).at(j) |= 2;
		}
	}

	for (auto& y : lifeMap)									// ����ϸ��״̬
		for (auto& x : y)
			x >>= 1;
}

void Lifegame::draw()const
{
	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			if (lifeMap.at(i).at(j))										// ��ǰ״̬�Ƿ���
																			// ���߳�ΪWDITH�ľ���
				solidrectangle(i * WIDTH, j * WIDTH, i * WIDTH + WIDTH - 1, j * WIDTH + WIDTH - 1);	
		}
	}
}