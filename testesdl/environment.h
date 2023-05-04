#include "cell.h"
#include <vector>
#pragma once
class environment
{
private:
	int width;
	int height;
	std::vector<std::vector<cell>> cells;

public :
	int getW();
	int getH();
	std::vector<std::vector<cell>> getCells();
	void setHome(int posx, int posy);
	void unsetHome(int posx, int posy);
	void createFood(int posx, int posy);
	void decay(int s);
	environment(int w, int h);
	
};

