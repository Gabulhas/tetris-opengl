#ifndef TETRIS_UTILS_H
#define TETRIS_UTILS_H
#include <iostream>
#include <ctime>

using namespace std;
//TODO: mudar para class

void sleep(float seconds){
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while(clock() < startClock+secondsAhead);
    return;
}

#endif //TETRIS_UTILS_H
