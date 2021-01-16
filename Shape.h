#ifndef TETRIS_SHAPE_H
#define TETRIS_SHAPE_H

#include "vector"
#include "Position.h"

using namespace std;

// referecia: https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.deviantart.com%2Fnick07208%2Fart%2FTetris-pieces-788517246&psig=AOvVaw3F-j-Eor42hRHKsAOSXUZ-&ust=1609946737073000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCLiIxI2Nhe4CFQAAAAAdAAAAABAJ
// https://www.google.com/url?sa=i&url=https%3A%2F%2Fmedium.com%2F%40markmliu%2Fthe-tetris-proof-60a7a69a8e04&psig=AOvVaw3F-j-Eor42hRHKsAOSXUZ-&ust=1609946737073000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCLiIxI2Nhe4CFQAAAAAdAAAAABAN

// TODO: https://en.wikipedia.org/wiki/Tetromino

class Shape {
public:
    Shape();

    Shape(char type);

//tracks the type of each square (for rendering)
    vector<vector<vector<int>>> myShape;

    //tracks all the coordinates of each square
    vector<vector<Position>> myCoordinates;
    int currentRotation = 0;

    void printShape();

    void rotateShape(int i);

    int getBlock(int row, int col);

    void printCoordinates();

    void move(char direction);
    vector<vector<Position>> getMove(char direction);
    void move(vector<vector<Position>> coordinates);
    void setCoordinates(vector<vector<Position>> coordinates);
    bool hasNegative();

private:
    void startCoordinates();


    vector<vector<Position>> moveAux(vector<vector<Position>> coordinates, char direction);
    vector<vector<Position>> moveChange(vector<vector<Position>> coordinates, int x, int y);

    void rotate_temp(int i);

};


#endif //TETRIS_SHAPE_H
