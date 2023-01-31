#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <random>
#include <conio.h>
#include <Windows.h>
#include "header.h"
#define WIDTH 50
#define HEIGHT 20

int main(void)
{
	char console[30];
	sprintf(console, "mode con: cols=%d lines=%d", WIDTH, HEIGHT);
	system(console);

	Snake snake = Snake(WIDTH, HEIGHT);
	Food food = Food();
	Manager manager = Manager(WIDTH, HEIGHT, &food, &snake);
	
	bool* state = &(manager.m_state);
	bool* is_food = &(manager.m_is_food);

	while (*state)
	{
		system("cls");
		printf("  Press key 'd':กๆ 'a':ก็ 'w':ก่ 's':ก้\n\n");
		
		if (snake.GetDir()) 
		{
			if (!(*is_food)) { manager.MakeFood(WIDTH, HEIGHT); }
		}

		if (_kbhit())
		{
			int input = _getch();
			snake.SetDir(input);
		}

		snake.Move();
		manager.Print();
		manager.CollisionCheck();
		
		Sleep(250);
	}

	system("cls");
	manager.GameOver();

	return 0;
}

