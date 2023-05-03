#pragma once
#include"environment.h"
class ant
{
private:
	bool food;
	int oldX;
	int oldY;
	int X;
	int Y;
	environment* env;
	int* detect_ferA();
	int* detect_ferB();
	void move_random();
	void move_to(int x, int y);
	ant(int x, int y, environment* e);
public:
	
	
	void action();
};

