//

// Created by guilherme on 04/01/21.
//

#include "Shape.h"
#include "cstdio"

// https://github.com/andykhv/Tetris3D/blob/master/src/shape.cpp


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

// i = 1 or i = -1 for 90 or -90
void Shape::rotateShape(int i) {

    int totalRotations = myShape.size();
    int nextRotation = currentRotation + i;
    printf("Next Rotation, %d\n", nextRotation);

    if (nextRotation < 0) {
        nextRotation = totalRotations - 1;
    } else if (nextRotation == totalRotations) {
        nextRotation = 0;
    }
    currentRotation = nextRotation;

}