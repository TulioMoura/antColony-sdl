#include "cell.h"

 cell::cell() {
    ferA = 0;
    ferB = 0;
    food = 0;
    home = false;
}

bool cell::getFood()
{
    if (food <= 0) {
        return false;
    }
    else {
        return true;
    }
    
}

void cell::addFood(int value)
{
    food = value;
}

int cell::getFerA()
{
    return ferA;
}

void cell::addFerA(int value)
{
    ferA = value;
}

int cell::getFerB()
{
    return ferB;
}

void cell::addFerB(int value)
{
    ferB = value;
}


void cell::setHome()
{
    home = true;
}

bool cell::getHome() {
    return home;
}

void cell::unsetHome()
{
    home =  false;
}
