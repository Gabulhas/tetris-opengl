//
// Created by guilherme on 04/01/21.
//

#ifndef TETRIS_SHAPE_H
#define TETRIS_SHAPE_H

#include "vector"

using namespace std;

// referecia: https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.deviantart.com%2Fnick07208%2Fart%2FTetris-pieces-788517246&psig=AOvVaw3F-j-Eor42hRHKsAOSXUZ-&ust=1609946737073000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCLiIxI2Nhe4CFQAAAAAdAAAAABAJ
// https://www.google.com/url?sa=i&url=https%3A%2F%2Fmedium.com%2F%40markmliu%2Fthe-tetris-proof-60a7a69a8e04&psig=AOvVaw3F-j-Eor42hRHKsAOSXUZ-&ust=1609946737073000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCLiIxI2Nhe4CFQAAAAAdAAAAABAN

// TODO: https://en.wikipedia.org/wiki/Tetromino

class Shape {
public:
    vector<vector<vector<int>>> myShape;
    int currentRotation = 0;

    Shape(char type);


    void printShape();

    void rotateShape();

    void rotateShape(int i);
};


#endif //TETRIS_SHAPE_H
