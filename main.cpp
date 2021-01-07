#include <cstdlib>
#include <cstdio>
#include "Board.h"
#include "Shape.h"
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h> // for sleep()

int main(void) {

    Board board = Board();
    board.newBoard();


    Shape shape = Shape();
    board.insertShape(&shape);
    //board.move_piece('D');
    board.print_state();
    char letter;

    for (;;) {
        char buf[20];
        fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
        sleep(1);
        int numRead = read(0, buf, 4);
        if (numRead > 0) {
            letter = numRead;
            cout<<numRead;
        } else {
            letter = 'D';
        }
        if (letter == 'U') {
            board.currentShape->rotateShape(1);
        }

        if (board.move_piece(letter)) {

            cout << "moved";
        } else {
            cout << "didn't move";
            if (letter == 'D') {
                shape = Shape();

                if (board.insertShape(&shape)) {
                    printf("PERDEU");
                    break;
                };

            }
        }
        cout << "\n\n";
        board.currentShape->printCoordinates();
        cout << "\n\n";
        board.print_state();

    }

}