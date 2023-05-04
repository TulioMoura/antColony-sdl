#pragma once
#include"environment.h"
#include<iostream>
class ant
{
private:
	bool food;
	int oldX;
	int oldY;
	int X;
	int Y;
	environment* env;
	std::vector<int> detect_ferA();
	std::vector<int> detect_ferB();
	void move_random();
	void move_to(int x, int y);

public:
	ant(int x, int y, environment* e);
	ant();
	int getX();
	int getY();
	void action();
};

