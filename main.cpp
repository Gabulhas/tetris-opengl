#include <cstdlib>
#include <cstdio>
#include "Board.h"
#include "Shape.h"

int main(void) {

    /*
    Board board = Board();
    board.newBoard();
    board.print_board();

     */

    Shape L = Shape('L');
    L.printShape();


    L.rotateShape(-1);
    L.printShape();
}