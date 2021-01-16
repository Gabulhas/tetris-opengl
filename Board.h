#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include "Position.h"
#include "Shape.h"

#define ROWS 20
#define COLUMNS 10
#define EMPTY 0

// TODO: https://github.com/janbodnar/Java-Tetris-Game/blob/master/com/zetcode/Shape.java

class Board {
public:
    vector<vector<int>> board;
    Board();
    void newBoard();
    void print_board();
    int shape_at(int x, int y);
    int shape_at(Position pos);

    Shape *currentShape;
    void clearBoard();

    bool insertShape(Shape *shape);

    vector<vector<int>> getcurrentState();
    bool move_piece(char direction);
    void print_state();
    void deleteRow(int row);
    vector<int> clearFullRows();
    bool rotate_piece();


private:
    bool isRowFull(int Row);

    bool check_collision_aux(vector<vector<Position>> state);

    void print_aux(vector<vector<int>> temp);

    void save_piece();

};


#endif //TETRIS_BOARD_H
