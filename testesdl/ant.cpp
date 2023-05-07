#include "ant.h"
#include "environment.h"
#include <exception>
#include <math.h>
#include <iostream>


ant::ant(int x, int y, environment* e) {
	if (x > e->getW() || y > e->getH()) {
		throw new _exception();
	}
	X = x;
	Y = y;
	env = e;
	oldX = x;
	oldY = y;
	food = false;
}
ant::ant() {
    env = nullptr;
    X = 0;
    Y = 0;
    oldX = 0;
    oldY = 0;
    food = false;
}
std::vector<int> ant::detect_ferA() {
    
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                else if ((X + i) >= 50 || (X + i) < 0 || (Y + j) < 0 || (Y + j) >= 50) {
                    continue;
                }
                else if (env->getCells(X + i, Y + j)->getFerA()> 1) {
                    std::vector<int> result = {X + i, Y + j};
                    return result ;
                }
                
            }
        }
        throw  _exception();

}
std::vector<int> ant::detect_ferB() {

    for (int i = -1; i < 2; i++) {
        for (int j = 1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            else if ((X + i) >=50 || (X + i) < 0 ||(Y+j)< 0 ||(Y+j)>=50) {
                continue;
            }
            else if (env->getCells(X + i,Y + j)->getFerB() > 1) {  //tratar caso em que a posição do agente é a borda, ou seja, X+1 > 50 < 0
                std::vector<int> result = { X + i, Y + j };
                return(result);
            }

        }
    }
    throw _exception();

}
void ant::move_random(){
    do {
        oldX = X;
        oldY = Y;
        X = X + round(rand() % 3 - 1); //CORRIGIR
        Y = Y + round(rand() % 3 - 1); //CORRIGIR
        if (X >= env->getW()) {
            X = env->getW() -2;
        }
        if (X < 0) {
            X = 0;
        }
        if (Y >= env->getH()) {
            Y = env->getH() -2;
        }
        if (Y < 0) {
            Y = 0;
        }
    } while (oldX == X && oldY == Y);
}

void ant::move_to(int x, int y) {
    if (x > env->getW() || y > env->getH()) {
        throw new _exception();
    }

    oldX = X;
    oldY = Y;
    X = x;
    Y = y;
}

int ant::getX()
{
    return X;
}

int ant::getY()
{
    return Y;
}

void ant::action() {
    //std:: cout << "action executed" << std::endl;
    if (food == false && env->getCells(X,Y)->getFood() == 0) {
        std::vector<int> fB;
        env->getCells(X, Y)->addFerA(1);
        try
        {
            fB = detect_ferB();
            move_to(fB[0], fB[1]);
        }
        catch (const _exception)
        {
            move_random();
        }
        
        
        

    }
    else if (food == false && env->getCells(X, Y)->getFood() > 0) {
        food = true;
        env->getCells(X, Y)->removeFood();
        env->getCells(X, Y)->addFerB(1);
    }
    else if (food == true) {
        env->getCells(X, Y)->addFerB(1);

        if (env->getCells(X, Y)->getHome() == true) {
            food = false;
            std::cout << "home";
        }
        
        else {
            std::vector<int> fA;

            try
            {
                fA = detect_ferA();
                move_to(fA[0], fA[1]);
            }
            catch (const _exception)
            {
                move_random();
            }
        }
        

    }
    

}
