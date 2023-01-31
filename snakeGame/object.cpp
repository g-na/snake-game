#include <stdio.h>
#include <random>
#include <time.h>
#include <Windows.h>
#include "header.h"

Foundation::Foundation()
{
	m_x = 0;
	m_y = 0;
}
Foundation::~Foundation() {}

void Foundation::GotoXY(int _x, int _y)
{
	COORD Pos;
	Pos.X = _x;
	Pos.Y = _y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

Map::Map(){}
Map::Map(int _w, int _h)
{
	m_x = _w;
	m_y = _h;
}
Map::~Map() {}
void Map::Print()
{
	for (int x = m_x; x > 0; x--) { printf ("X"); }
	for (int y = 0; y < m_y - 4; y++)
	{
		for (int x = 0; x < m_x; x++)
		{
			if (x == 0 || x == m_x - 1) { printf("X"); }
			else { printf(" "); }
		}
	}
	for (int x = m_x; x > 0; x--) { printf("X"); }
}

Food::Food()
{
	m_x = 0;
	m_y = 0;
}

Food::~Food() {}

void Food::MakeFood(int _w, int _h)
{
	srand(time(NULL));
	m_x = (rand() % (_w-4)) + 2;
	m_y = (rand() % (_h-4)) + 3;
}

void Food::Print()
{
	GotoXY(m_x, m_y);
	printf("F");
}