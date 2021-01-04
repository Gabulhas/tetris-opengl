//
// Created by guilherme on 04/01/21.
//

#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include "Position.h"

#define ROWS 22
#define COLUMNS 10
#define EMPTY 0

// TODO: https://github.com/janbodnar/Java-Tetris-Game/blob/master/com/zetcode/Shape.java

class Board {
public:
    int board[ROWS][COLUMNS] {};
    Board();
    void newBoard();
    void print_board();
    int shape_at(int x, int y);
    int shape_at(Position pos);

    void clearBoard();

    bool isRowFull(int Row);
};


#endif //TETRIS_BOARD_H
