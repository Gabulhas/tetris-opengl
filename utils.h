//
// Created by guilherme on 09/01/21.
//

#ifndef TETRIS_UTILS_H
#define TETRIS_UTILS_H
#include <iostream>
#include <ctime>

using namespace std;

void sleep(float seconds){
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while(clock() < startClock+secondsAhead);
    return;
}

#endif //TETRIS_UTILS_H
