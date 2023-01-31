#include <stdio.h>
#include "header.h"

Manager::Manager(int _w, int _h, Food* _food, Snake* _snake)
{
	m_map = Map(_w, _h);
	m_food = _food;
	m_snake = _snake;
	m_score = 0;
	m_state = true;
	m_is_food = false;
}
Manager::~Manager() {}

void Manager::MakeFood(int _w, int _h)
{
	m_food->MakeFood(_w, _h);
	m_is_food = true;
}

void Manager::CollisionCheck()
{
	int fx = m_food->m_x;	int fy = m_food->m_y;
	int* sx = &(m_snake->GetHead()->m_x); 
	int* sy = &(m_snake->GetHead()->m_y);
	int mx = m_map.m_x; int my = m_map.m_y;

	if (m_is_food)
	{
		if (fx == *sx && fy == *sy)
		{
			m_score++;
			m_is_food = false;
			m_snake->PushBack();
		}
	}

	if (*sx >= mx || *sx <= 2 || *sy >= my || *sy <= 2)
	{
		*sx = 0; *sy = 0;
		m_state = false;
	}
}

void Manager::Print()
{
	m_map.Print();
	if (m_is_food) m_food->Print();
	m_snake->Print();
}

void Manager::GameOver()
{
	printf("\n\n\n\n");
	printf("\t==========================\n");
	printf("\t        Game Over\n        ");
	printf("\tscore: %d\n", m_score);
	printf("\t==========================");
}