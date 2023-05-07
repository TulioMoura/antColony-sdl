#include "environment.h"
#include "cell.h"
#include <cmath>
#include <vector>
void environment::createFood(int posx,int  posy,int r) {
    int xLowLim = ((posx - r) < 0) ? 0 : posx - r;
    int xUpLim = ((posx + r) > width) ? width : posx + r;
    int yLowLim = ((posy - r) < 0) ? 0 : posy - r;
    int yUpLim = ((posy + r) > height) ? height : posy + r;
    for (int i = yLowLim; i < yUpLim; i++) {
        for (int j = xLowLim; j < xUpLim; j++) {
            int x = std::pow(std::abs(j - posx), 2);
            int y = std::pow(std::abs(i - posy), 2);
            int h = std::sqrt(x + y);
            if (h < r) {
                cells[i][j].addFood(5);
            }
        }
    }
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

void environment::setHome(int posx, int posy,int r) {
    int xLowLim = ((posx - r) < 0) ? 0 : posx - r;
    int xUpLim = ((posx + r) > width) ? width : posx + r;
    int yLowLim = ((posy - r) < 0) ? 0 : posy - r;
    int yUpLim = ((posy + r) > height) ? height : posy + r;
    for (int i = yLowLim; i < yUpLim; i++) {
        for (int j = xLowLim; j < xUpLim; j++) {
            int x = std::pow(std::abs(j - posx), 2);
            int y = std::pow(std::abs(i - posy), 2);
            int h = std::sqrt(x + y);
            if (h < r) {
                cells[i][j].setHome();
            }
        }
    }
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

cell* environment::getCells(int x, int y) {
        return ((cells.data() + x)->data() + y);
}