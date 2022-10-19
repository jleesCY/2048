#include "board.h"

// getters
int Board::getWidth() {
    return width;
}
int Board::getHeight() {
    return height;
}
int Board::getLoc(int x, int y) {
    return board[x][y];
}
int Board::getScore() {
    return score;
}
int Board::getEmptySize() {
    return empty.size();
}

// setters
void Board::setLoc(int x, int y, int n) {
    board[y][x] = n;
    updateEmpty();
}
void Board::setScore(int s) {
    score = s;
}

// directions
bool Board::up() {
    bool b = false;
    // move cells
    for (int l = 0; l < height - 1; l++) {
        for (int i = 1; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i-1][j] == 0 && board[i][j] != 0) {
                    board[i-1][j] = board[i][j];
                    board[i][j] = 0;
                    b = true;
                }
            }
        }
    }
    // combine cells
    for (int i = 1; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i-1][j] == board[i][j] && board[i][j] != 0) {
                board[i-1][j] *= 2;
                score += board[i-1][j];
                board[i][j] = 0;
                b = true;
            }
        }
    }
    // re-shift cells
    for (int i = 1; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i-1][j] == 0 && board[i][j] != 0) {
                board[i-1][j] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
    updateEmpty();
    return b;
}

bool Board::down() {
    bool b = false;
    // move cells
    for (int l = 0; l < height - 1; l++) {
        for (int i = height - 2; i > -1; i--) {
            for (int j = 0; j < width; j++) {
                if (board[i+1][j] == 0 && board[i][j] != 0) {
                    board[i+1][j] = board[i][j];
                    board[i][j] = 0;
                    b = true;
                }
            }
        }
    }
    // combine cells
    for (int i = height - 2; i > -1; i--) {
        for (int j = 0; j < width; j++) {
            if (board[i+1][j] == board[i][j] && board[i][j] != 0) {
                board[i+1][j] *= 2;
                score += board[i+1][j];
                board[i][j] = 0;
                b = true;
            }
        }
    }
    // re-shift cells
    for (int i = height - 2; i > -1; i--) {
        for (int j = 0; j < width; j++) {
            if (board[i+1][j] == 0 && board[i][j] != 0) {
                board[i+1][j] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
    updateEmpty();
    return b;
}

bool Board::left() {
    bool b = false;
    // move cells
    for (int l = 0; l < width - 1; l++) {
        for (int j = 1; j < width; j++) {
            for (int i = 0; i < height; i++) {
                if (board[i][j-1] == 0 && board[i][j] != 0) {
                    board[i][j-1] = board[i][j];
                    board[i][j] = 0;
                    b = true;
                }
            }
        }
    }
    // combine cells
    for (int j = 1; j < width; j++) {
        for (int i = 0; i < height; i++) {
            if (board[i][j-1] == board[i][j] && board[i][j] != 0) {
                board[i][j-1] *= 2;
                score += board[i][j-1];
                board[i][j] = 0;
                b = true;
            }
        }
    }
    // re-shift cells
    for (int j = 1; j < width; j++) {
        for (int i = 0; i < height; i++) {
            if (board[i][j-1] == 0 && board[i][j] != 0) {
                board[i][j-1] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
    updateEmpty();
    return b;
}

bool Board::right() {
    bool b = false;
    // move cells
    for (int l = 0; l < width - 1; l++) {
        for (int j = width - 2; j > -1; j--) {
            for (int i = 0; i < height; i++) {
                if (board[i][j+1] == 0 && board[i][j] != 0) {
                    board[i][j+1] = board[i][j];
                    board[i][j] = 0;
                    b = true;
                }
            }
        }
    }
    // combine cells
    for (int j = width - 2; j > -1; j--) {
        for (int i = 0; i < height; i++) {
            if (board[i][j+1] == board[i][j] && board[i][j] != 0) {
                board[i][j+1] *= 2;
                score += board[i][j+1];
                board[i][j] = 0;
                b = true;
            }
        }
    }
    // re-shift cells
    for (int j = width - 2; j > -1; j--) {
        for (int i = 0; i < height; i++) {
            if (board[i][j+1] == 0 && board[i][j] != 0) {
                board[i][j+1] = board[i][j];
                board[i][j] = 0;
            }
        }
    }
    updateEmpty();
    return b;
}

// other
void Board::fill(int n) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = n;
        }
    }
}

void Board::print() {
    string num;
    // print top bar
    cout << "#";
    for (int i = 0; i < width; i++) {
        cout << "------#";
    }
    cout << "\n";

    for(int i = 0; i < height; i++) {
        cout << "|";
        for (int x = 0; x < width; x++) {
            cout << "      |";
        }
        cout << "\n";
        for(int j = 0; j < width; j++) {
            int n = board[i][j];

            if (j == 0) {
                // print left bar
                cout << "| ";
                // print number

            }
            switch (to_string(n).length()) {
                case 1:
                    if (n != 0) {
                        cout << "   " << n << " | ";
                    }
                    else {
                        cout << "     | ";
                    }

                    break;
                case 2:
                    cout << "  " << n << " | ";
                    break;
                case 3:
                    cout << " " << n << " | ";
                    break;
                case 4:
                    cout << n << " | ";
                    break;
            };
        }
        cout << "\n|";
        for (int x = 0; x < width; x++) {
            cout << "      |";
        }
        cout << "\n";
        if (i < (height - 1)) {
            cout << "#";
            for (int i = 0; i < width; i++) {
                if (i < width - 1)
                    cout << "------+";
                else {
                    cout << "------#";
                    break;
                }
            }
            cout << "\n";
        }
        else {
            cout << "#";
            for (int i = 0; i < width; i++) {
                cout << "------#";
            }
            cout << "\n";
        }
    }
}

void Board::add(bool b) {
    if (b) {
        srand(time(NULL));
        int i = rand() % empty.size();
        int h = empty[i][0];
        int w = empty[i][1];

        setLoc(h, w, 2);
        updateEmpty();
    }
}

void Board::updateEmpty() {
    vector<int> temp(2);
    empty.clear();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == 0) {
                // fill empty
                temp[0] = j;
                temp[1] = i;
                empty.push_back(temp);
            }
        }
    }
}

bool Board::noMoves() {
    bool good = true;
    int val;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // check north
            if (i != 0) {
                val = board[i-1][j];
                if (val == board[i][j]) {
                    good = false;
                }
            }
            // check south
            if (i != (height - 1)) {
                val = board[i+1][j];
                if (val == board[i][j]) {
                    good = false;
                }
            }
            // check east
            if (j != (width - 1)) {
                val = board[i][j+1];
                if (val == board[i][j]) {
                    good = false;
                }
            }
            // check west
            if (j != 0) {
                val = board[i][j-1];
                if (val == board[i][j]) {
                    good = false;
                }
            }
        }
    }
    return good;
}