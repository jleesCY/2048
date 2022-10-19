#include "headers.h"
#include "board.cpp"

int main() {
    int size;
    int val;
    cout << "Welome to J-Sneez's 2048 Ripoff!\n[Q] - quit at any time\nWhat size board do you want?: ";
    cin >> size;
    Board board = Board(size);
    cout << "\n";
    system("pause");

    // initial print
    system("cls");
    board.add(true);
    board.print();
    cout << "Score: 0\n";
    bool b;

    // game loop
    while (val != 'q') { 
        b = false;
        if (board.getEmptySize() == 0 ) {
            if (board.noMoves()) {
                cout << "Out of Moves! Game Over!\n";
                system("pause");
                return 0;
            }
        }
        switch(val = getch()) {
        // up
        case KEY_UP:
            b = board.up();
            board.add(b);
            system("cls");
            board.print();
            cout << "Score: " << board.getScore() << "\n";
            break;
        // down
        case KEY_DOWN:
            b = board.down();
            board.add(b);
            system("cls");
            board.print();
            cout << "Score: " << board.getScore() << "\n";
            break;
        // left
        case KEY_LEFT:
            b = board.left();
            board.add(b);
            system("cls");
            board.print();
            cout << "Score: " << board.getScore() << "\n";
            break;
        // right
        case KEY_RIGHT:
            b = board.right();
            board.add(b);
            system("cls");
            board.print();
            cout << "Score: " << board.getScore() << "\n";
            break;
        case 'q':
            cout << "Sad to see you go :(\n";
            break;
        };
    }
    system("pause");
    return 0;
}