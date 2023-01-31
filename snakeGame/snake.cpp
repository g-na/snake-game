#include <stdio.h>
#include <time.h>
#include <random>
#include "header.h"

Node::Node()
{
	m_next = nullptr;
	m_prev = nullptr;
	m_x = 0;
	m_y = 0;
}
Node::~Node() {}

Snake::Snake(int _x, int _y)
{
	Init(_x, _y);
}
Snake::~Snake()
{
	Node* node = m_head;
	Node* nextNode = nullptr;

	while (node != nullptr)
	{
		nextNode = node->m_next;
		delete node;
		node = nextNode;
	}
}

void Snake::Init(int _x, int _y)
{
	m_head = nullptr;
	m_tail = nullptr;
	m_dir = 0;
	
	srand(time(NULL));
	int x = (rand() % (_x-10)) + 2;
	int y = (rand() % (_y-10)) + 4;
	PushBack();
	m_head->m_x = x;
	m_head->m_y = y;
}

void Snake::PushBack()
{
	Node* node = new Node();

	if (m_tail == nullptr) { m_head = node; }
	else
	{
		m_tail->m_next = node;
		node->m_prev = m_tail;
	}
	m_tail = node;
}

void Snake::SetDir(int _input)
{
	switch (_input)
	{
	case 'w': m_dir = 1; break;
	case 'a': m_dir = 2; break;
	case 's': m_dir = 3; break;
	case 'd': m_dir = 4; break;
	default: break;
	}
}

void Snake::Move()
{
	if (m_tail != m_head)
	{
		Node* node = m_tail;
		Node* prevNode = nullptr;
		while (node != m_head)
		{
			prevNode = node->m_prev;

			node->m_x = prevNode->m_x;
			node->m_y = prevNode->m_y;

			node = prevNode;
		}
	}
	
	switch (m_dir)
	{
	case 0: break;
	case 1: m_head->m_y--; break;
	case 2: m_head->m_x--; break;
	case 3: m_head->m_y++; break;
	case 4: m_head->m_x++; break;
	}
}

void Snake::Print()
{
	Node* node = m_head;
	while (node)
	{
		GotoXY(node->m_x, node->m_y);
		if (node == m_head) { printf("O"); }
		else (printf("o"));
		node = node->m_next;
	}
}
