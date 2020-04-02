#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <graphics.h>

using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;

constexpr auto WIDTH = 8;						// 细胞大小		单位 : 像素
constexpr auto NUMS = 80;						// 行列细胞数量
constexpr auto PROBABILITY = 10 / 100.0;		// 初始细胞为生的概率 
constexpr auto TIME = 200;						// 运行间隔时间 单位 : ms

class Lifegame
{
private:
	int mapSize;								// 细胞生存的地图大小
	vector<vector<int>> lifeMap;				// 细胞存活状态
	explicit Lifegame(int s = NUMS);			// 单例模式
	Lifegame(const Lifegame& li) = delete;
	Lifegame& operator=(const Lifegame& li) = delete;

public:
	static Lifegame& onlyObject()noexcept;
	void play();
	void life();
	void draw()const;
};