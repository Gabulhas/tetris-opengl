//
// Created by guilherme on 04/01/21.
//

#include <vector>
#include "Board.h"
#include "cstdio"
#include "Position.h"
#include "Shape.h"

#define X_START 5

using namespace std;

Board::Board() {
    newBoard();
};

void Board::newBoard() {
    for (int i = 0; i < ROWS; i++) {
        board.push_back(vector<int>());
        for (int j = 0; j < COLUMNS; j++) {
            board.at(i).push_back(0);
        }
    }
}

int Board::shape_at(Position pos) {
    return board[pos.x][pos.y];
};

int Board::shape_at(int x, int y) {
    return board[x][y];
};

void Board::clearBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board.at(i).at(j) = 0;
        }
    }
}

bool Board::isRowFull(int Row) {
    for (int i = 0; i < COLUMNS; i++) {
        if (board[Row][i] == EMPTY) {
            return false;
        }
    }
    return true;
}

//TODO: adicionar collision e perder o jogo
bool Board::insertShape(Shape *shape) {
    currentShape = shape;
    for (int i = 0; i < shape->myCoordinates.size(); i++) {
        for (int j = 0; j < shape->myCoordinates.at(i).size(); j++) {
            Position temp = shape->myCoordinates[i][j];
            shape->myCoordinates[i][j] = Position(j + X_START, temp.y);
        }
    }
    if (check_collision_aux(shape->myCoordinates)) {
        printf("\n#######DED########3\n");
        return false;
    }
    return true;

}

//Calculates Board with the Piece on it, used for rendering
vector<vector<int>> Board::getcurrentState() {
    vector<vector<int>> currentState = board;
    for (int i = 0; i < currentShape->myCoordinates.size(); i++) {
        for (int j = 0; j < currentShape->myCoordinates.at(i).size(); j++) {
            Position temp = currentShape->myCoordinates.at(i).at(j);
            int block = currentShape->getBlock(i, j);
            if (temp.x >= 0 && temp.y >= 0 && block != 0) {
                currentState.at(temp.y).at(temp.x) = block;
            }
        }
    }
    return currentState;

}


bool Board::move_piece(char direction) {


    vector<vector<Position>> state = currentShape->getMove(direction);

    if (check_collision_aux(state)) {
        //piece reached the bottom
        if (direction == 'D') {
            save_piece();
        }
        return false;
    }
    currentShape->move(state);
    return true;
}

void Board::save_piece() {
    board = getcurrentState();
}


bool Board::check_collision_aux(vector<vector<Position>> state) {

    for (int i = 0; i < state.size(); i++) {
        for (int j = 0; j < state.at(i).size(); j++) {
            if (currentShape->getBlock(i, j) != 0) {
                Position temp = state.at(i).at(j);

                if (temp.x < 0 || temp.x > COLUMNS - 1 ||
                    temp.y > ROWS - 1) {
                    return true;
                }
                if (temp.y > 0) {
                    if (board[temp.y][temp.x] != EMPTY) {
                        fflush(stdout);
                        printf("Piece collusion");

                        return true;
                    }
                }
            }
        }
    }
    return false;


}

void Board::print_state() {
    print_aux(getcurrentState());
}

void Board::print_board() {
    print_aux(board);
}

void Board::print_aux(vector<vector<int>> temp) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (temp[i][j] == 0) {
                printf(".");
            } else {
                printf("%d", temp[i][j]);
            }
        }
        printf("\n");
    }
}


vector<int> Board::clearFullRows() {
    vector<int> clearedRows;
    bool flag = false;

    for (int i = 0; i < ROWS; i++) {
        if (isRowFull(i)) {
            deleteRow(i);
            clearedRows.push_back(i);
            flag = true;
        }
    }
    if (flag) {
        fflush(stdout);
        printf("CLEARING");
        fflush(stdout);
    }
    return clearedRows;
}


void Board::deleteRow(int row) {
    for (int i = 0; i < COLUMNS; i++) {
        board.at(row).at(i) = 0;
    }
    for (int i = row - 1; i >= 0; i--) {
        board.at(i + 1) = board.at(i);
    }
    for (int i = 0; i < COLUMNS; i++) {
        board.at(0).at(i) = 0;
    }
}