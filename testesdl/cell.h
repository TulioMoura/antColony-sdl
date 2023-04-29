#pragma once
class cell
{
private:
	int food;
	int ferA;
	int ferB;
	bool home;
public:
	 cell();

	bool getFood();
	void addFood(int value);
	
	int getFerA();
	void addFerA(int value);

	int getFerB();
	void addFerB(int value);

	void setHome();
	bool getHome();
	void unsetHome();
};

