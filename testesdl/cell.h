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
	void removeFood();
	
	int getFerA();
	void addFerA(int value);

	int getFerB();
	void addFerB(int value);

	void decay(int s);

	void setHome();
	bool getHome();
	void unsetHome();
};

