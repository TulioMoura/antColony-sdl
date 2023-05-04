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
void cell::removeFood() {
    food = food--;
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
    ferA = ferA + value;
}

int cell::getFerB()
{
    return ferB;
}

void cell::addFerB(int value)
{
    ferB = ferB+value;
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

void cell::decay(int s) {
    ferA = (ferA + s) < 0 ? 0 : ferA + s;
    ferB - (ferB + s) < 0 ? 0 : ferB + s;

    
}