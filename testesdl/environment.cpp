#include "environment.h"
#include "cell.h"
#include <vector>
void environment::createFood(int posx,int  posy) {
    cells[posx][posy].addFood(20);
    cells[posx + 1][posy + 1].addFood(20);
    cells[posx - 1][posy - 1].addFood(20);
    cells[posx + 1][posy].addFood(20);
    cells[posx - 1][posy].addFood(20);
    cells[posx][posy - 1].addFood(20);
    cells[posx][posy + 1].addFood(20);
}

environment::environment(int w, int h) {
    width = w;
    height = h;
    cells.resize(width, std::vector<cell>(height));

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

void environment::decay(int s) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cells[i][j].decay(s);
        }
    }
}

std::vector<std::vector<cell>> environment::getCells() {
    return cells;
}