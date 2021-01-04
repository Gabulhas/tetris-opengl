#include <cstdlib>
#include <cstdio>
#include "Board.h"

int main(void){

    Board board = Board();
    board.newBoard();
    board.print_board();
}