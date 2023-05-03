#include "ant.h"
#include "environment.h"
#include <exception>
#include <math.h>

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

int* ant::detect_ferA() {
    
        for (int i = -1; i < 2; i++) {
            for (int j = 1; j < 2; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                else if (env->getCells()[X + i][Y + j].getFerA()> 1) {
                    int result[] = {X + i, Y + j};
                    return(&result[0]);
                }
                
            }
        }
        throw new _exception();

    
}
int* ant::detect_ferB() {

    for (int i = -1; i < 2; i++) {
        for (int j = 1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            else if (env->getCells()[X + i][Y + j].getFerB() > 1) {
                int result[] = { X + i, Y + j };
                return(&result[0]);
            }

        }
    }
    throw new _exception();


}
void ant::move_random(){
    do {
        oldX = X;
        oldY = Y;
        X = X + round(rand() * 2 - 1);
        Y = Y + round(rand() * 2 - 1);
            if (X >= env->getW()) {
                X = env->getW()-1;
            }
        if (X < 0) {
            X = 0;
        }
        if (Y >= env->getH()) {
            Y = env->getH()-1;
        }
        if (Y < 0) {
            Y = 0;
        }
    } while (X == oldX && Y == oldY);
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

void ant::action() {
    if (food == false && env->getCells()[X][Y].getFood() == 0) {
        int* fB;
        env->getCells()[X][Y].addFerA(1);
        try
        {
            fB = detect_ferB();
            move_to(fB[0], fB[1]);
        }
        catch (const std::exception&)
        {
            move_random();
        }
        
        
        

    }
    else if (food == false && env->getCells()[X][Y].getFood() > 0) {
        food = true;
        env->getCells()[X][Y].removeFood();
        env->getCells()[X][Y].addFerB(1);
    }
    if (food == true) {
        env->getCells()[X][Y].addFerB(1);

        if (env->getCells()[X][Y].getHome() == true) {
            food = false;
        }
        
        else {
            int* fA;

            try
            {
                fA = detect_ferA();
                move_to(fA[0], fA[1]);
            }
            catch (const std::exception&)
            {
                move_random();
            }
        }
        

    }
    

}
