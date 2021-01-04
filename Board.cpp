//
// Created by guilherme on 04/01/21.
//

#include <vector>
#include "Board.h"
#include "cstdio"
#include "Position.h"

using namespace std;

Board::Board() {
    newBoard();
};

void Board::newBoard() {
    std::fill(*board, *board + sizeof(int), EMPTY);
}

int Board::shape_at(Position pos) {
    return board[pos.x][pos.y];
};

int Board::shape_at(int x, int y) {
    return board[x][y];
};

void Board::clearBoard(){
    newBoard();
}

bool Board::isRowFull(int Row){
    for(int i = 0; i < COLUMNS; i++) {
        if(board[Row][i] != EMPTY){
            return false;
        }
    }
    return true;

}

void Board::print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}
