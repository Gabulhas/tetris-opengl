//
// Created by guilherme on 04/01/21.
//

#include <cstdio>
#include "Position.h"

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
}

void Position::print() {
    printf("[%d,%d]", x, y);
}