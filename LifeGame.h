#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <graphics.h>

using std::vector;
using std::default_random_engine;
using std::uniform_int_distribution;

constexpr auto WIDTH = 8;						// ϸ����С		��λ : ����
constexpr auto NUMS = 80;						// ����ϸ������
constexpr auto PROBABILITY = 10 / 100.0;		// ��ʼϸ��Ϊ���ĸ��� 
constexpr auto TIME = 200;						// ���м��ʱ�� ��λ : ms

class Lifegame
{
private:
	int mapSize;								// ϸ������ĵ�ͼ��С
	vector<vector<int>> lifeMap;				// ϸ�����״̬
	explicit Lifegame(int s = NUMS);			// ����ģʽ
	Lifegame(const Lifegame& li) = delete;
	Lifegame& operator=(const Lifegame& li) = delete;

public:
	static Lifegame& onlyObject()noexcept;
	void play();
	void life();
	void draw()const;
};