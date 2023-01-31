#pragma once
class Foundation
{
private:
public:
	int m_x;
	int m_y;
	Foundation();
	~Foundation();
	void GotoXY(int x, int y);
};

class Food : public Foundation
{
private:
public:
	Food();
	~Food();
	void MakeFood(int _w, int _h);
	void Print();
};

class Node : public Foundation
{
private:
public:
	Node* m_next;
	Node* m_prev;
	Node();
	~Node();
};

class Snake : public Foundation
{
private:
	Node* m_head;
	Node* m_tail;
	int m_dir; // 0:, 1:w 2:a 3:s 4:d
public:
	Snake(int _x, int _y);
	~Snake();
	void Init(int _x, int _y);
	void PushBack();
	void SetDir(int _input);
	void Move();
	void Print();
	Node* GetHead() { return m_head; }
	int GetDir() { return m_dir; }
};

class Map : public Foundation
{
private:
public:
	Map();
	Map(int width, int height);
	~Map();
	void Print();
};

class Manager
{
private:
	int m_score;
	Food* m_food;
	Snake* m_snake;
	Map m_map;
public:
	bool m_state;
	bool m_is_food;
	Manager(int _width, int _height, Food* _food, Snake* _snake);
	~Manager();
	void MakeFood(int _w, int _h);
	void CollisionCheck();
	void Print();
	void GameOver();
};