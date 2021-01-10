//

// Created by guilherme on 04/01/21.
//

#include <time.h>
#include <cstdlib>
#include "Shape.h"
#include "cstdio"

// https://github.com/andykhv/Tetris3D/blob/master/src/shape.cpp

#define BLOCK_WIDTH 4
#define BLOCK_HEIGHT 4

// TYPE_SHAPE [ROTATION][ROW][COLUMN]
vector<vector<vector<int>>> O_SHAPE = {
        {
                {1, 1, 0, 0},
                {1, 1, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
        }};
vector<vector<vector<int>>> T_SHAPE = {//T shape
        {
                {0, 2, 0, 0},
                {2, 2, 2, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
        },
        {
                {2, 0, 0, 0},
                {2, 2, 0, 0},
                {2, 0, 0, 0},
                {0, 0, 0, 0}

        },
        {
                {2, 2, 2, 0},
                {0, 2, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
        },
        {
                {0, 2, 0, 0},
                {2, 2, 0, 0},
                {0, 2, 0, 0},
                {0, 0, 0, 0}
        }
};

vector<vector<vector<int>>> S_SHAPE = {//S shape
        {
                {0, 3, 3, 0},
                {3, 3, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
        },
        {
                {3, 0, 0, 0},
                {3, 3, 0, 0},
                {0, 3, 0, 0},
                {0, 0, 0, 0}

        }
};
vector<vector<vector<int>>> Z_SHAPE =
        {//Z shape
                {
                        {4, 4, 0, 0},
                        {0, 4, 4, 0},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}
                },
                {
                        {0, 4, 0, 0},
                        {4, 4, 0, 0},
                        {4, 0, 0, 0},
                        {0, 0, 0, 0}
                }

        };
vector<vector<vector<int>>> L_SHAPE = {//L shape
        {
                {
                        5, 0, 0, 0},
                {
                        5, 5, 5, 0},
                {
                        0, 0, 0, 0},
                {
                        0, 0, 0, 0}
        },
        {
                {
                        5, 5, 0, 0},
                {
                        5, 0, 0, 0},
                {
                        5, 0, 0, 0},
                {
                        0, 0, 0, 0}

        },
        {
                {
                        5, 5, 5, 0},
                {
                        0, 0, 5, 0},
                {
                        0, 0, 0, 0},
                {
                        0, 0, 0, 0}
        },
        {
                {
                        0, 5, 0, 0},
                {
                        0, 5, 0, 0},
                {
                        5, 5, 0, 0},
                {
                        0, 0, 0, 0}
        }
};
vector<vector<vector<int>>> J_SHAPE{//J shape
        {
                {
                        0, 0, 6, 0},
                {
                        6, 6, 6, 0},
                {
                        0, 0, 0, 0},
                {
                        0, 0, 0, 0}
        },
        {
                {
                        6, 0, 0, 0},
                {
                        6, 0, 0, 0},
                {
                        6, 6, 0, 0},
                {
                        0, 0, 0, 0}

        },
        {
                {
                        6, 6, 6, 0},
                {
                        6, 0, 0, 0},
                {
                        0, 0, 0, 0},
                {
                        0, 0, 0, 0}
        },
        {
                {
                        6, 6, 0, 0},
                {
                        0, 6, 0, 0},
                {
                        0, 6, 0, 0},
                {
                        0, 0, 0, 0}
        }
};
vector<vector<vector<int>>> I_SHAPE = {//I shape
        {
                {
                        7, 7, 7, 7},
                {
                        0, 0, 0, 0},
                {
                        0, 0, 0, 0},
                {
                        0, 0, 0, 0}
        },
        {
                {
                        7, 0, 0, 0},
                {
                        7, 0, 0, 0},
                {
                        7, 0, 0, 0},
                {
                        7, 0, 0, 0}
        }};

/*
 * Tipos possiveis:
 * O
 * I
 * S
 * Z
 * L
 * J
 * T
 *
 Ver referencia https://miro.medium.com/max/679/0*XduzlQ6FEPgqwiOy.
 */

char pieces_types[7] = {'O', 'I', 'S', 'Z', 'L', 'J', 'T'};

Shape::Shape() {
    srand(time(NULL));

    char type = pieces_types[rand() % 7];

    switch (type) {
        case 'O':
            myShape = O_SHAPE;
            break;
        case 'I':
            myShape = I_SHAPE;
            break;
        case 'S':
            myShape = S_SHAPE;
            break;
        case 'Z':
            myShape = Z_SHAPE;
            break;
        case 'L':
            myShape = L_SHAPE;
            break;
        case 'J':
            myShape = J_SHAPE;
            break;
        case 'T':
            myShape = T_SHAPE;
            break;

    }
    startCoordinates();

}


Shape::Shape(char type) {
    switch (type) {
        case 'O':
            myShape = O_SHAPE;
            break;
        case 'I':
            myShape = I_SHAPE;
            break;
        case 'S':
            myShape = S_SHAPE;
            break;
        case 'Z':
            myShape = Z_SHAPE;
            break;
        case 'L':
            myShape = L_SHAPE;
            break;
        case 'J':
            myShape = J_SHAPE;
            break;
        case 'T':
            myShape = T_SHAPE;
            break;

    }
    startCoordinates();
}


void Shape::startCoordinates() {


    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        myCoordinates.push_back(vector<Position>());
    }
    for (int i = BLOCK_HEIGHT - 1; i >= 0; i--) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            myCoordinates.at(i).push_back(Position(-1, -(BLOCK_HEIGHT - i)));
        }
    }
}

void Shape::printShape() {

    for (int j = 0; j < myShape.at(currentRotation).size(); j++) {

        for (int k = 0; k < myShape.at(currentRotation).at(j).size(); k++) {
            printf("%d", myShape.at(currentRotation).at(j).at(k));
        }
        printf("\n");
    }
    printf("\n\n");
}

void Shape::printCoordinates() {

    for (int i = 0; i < BLOCK_HEIGHT; i++) {
        for (int j = 0; j < BLOCK_WIDTH; j++) {
            myCoordinates[i][j].print();
        }
        printf("\n");
    }
    printf("\n\n");

}

int Shape::getBlock(int row, int col) {
    return myShape[currentRotation][row][col];
}


//Used for collision detection
vector<vector<Position>> Shape::getMove(char direction) {
    return moveAux(myCoordinates, direction);
}

//Used for definitive move
void Shape::move(char direction) {
    myCoordinates = moveAux(myCoordinates, direction);
}

void Shape::move(vector<vector<Position>> coordinates) {
    myCoordinates = coordinates;
}

void Shape::setCoordinates(vector<vector<Position>> coordinates) {
    myCoordinates = coordinates;
}

vector<vector<Position>> Shape::moveAux(vector<vector<Position>> coordinates, char direction) {
    switch (direction) {
        case 'D':
            return moveChange(coordinates, 0, 1);
        case 'L':
            return moveChange(coordinates, -1, 0);
        case 'R':
            return moveChange(coordinates, 1, 0);
        default:
            return coordinates;
    }
}

//x, y is math vector
vector<vector<Position>> Shape::moveChange(vector<vector<Position>> coordinates, int x, int y) {
    for (int i = 0; i < coordinates.size(); i++) {
        for (int j = 0; j < coordinates.at(i).size(); j++) {
            Position temp = coordinates.at(i).at(j);

            coordinates.at(i).at(j) = Position(temp.x + x, temp.y + y);
        }
    }
    return coordinates;
}


// i = 1 or i = -1 for 90 or -90

void Shape::rotateShape(int i) {
    rotate_temp(i);

}


void Shape::rotate_temp(int i) {

    int totalRotations = myShape.size();
    int nextRotation = currentRotation + i;

    if (nextRotation < 0) {
        nextRotation = totalRotations - 1;
    } else if (nextRotation == totalRotations) {
        nextRotation = 0;
    }
    currentRotation = nextRotation;

}

bool Shape::hasNegative() {
    for (int i = 0; i < myCoordinates.size(); i++) {
        for (int j = 0; j < myCoordinates.at(i).size(); j++) {
            if (myCoordinates.at(i).at(j).y < 0) {
                return true;
            }
        }
    }
    return false;
}