#include "environment.h"

void environment::createFood(int posx,int  posy) {
    cells[posx][posy].addFood(20);
    cells[posx + 1][posy + 1].addFood(20);
    cells[posx - 1][posy - 1].addFood(20);
    cells[posx + 1][posy].addFood(20);
    cells[posx - 1][posy].addFood(20);
    cells[posx][posy - 1].addFood(20);
    cells[posx][posy + 1].addFood(20);
}

environment::environment() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            cells[i][j] = cell();
        }
    }
}

int environment::getH() {
    return height;
}
int environment::getW() {
    return width;
}

void environment::setHome(int posx, int posy) {
    cells[posx][posy].setHome();
}
void environment::unsetHome(int posx, int posy) {
    cells[posx][posy].unsetHome();
}


std::vector<std::vector<cell>> environment::getCells() {
    return cells;
}