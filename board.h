#include "headers.h"

class Board {
    public:
    
    // constructors
    Board(int s) {
        width = s;
        height = s;
        score = 0;
        board.resize(width, vector<int>(height));
        empty.resize(0, vector<int>(2));
        vector<int> temp(2);
        // fill with zeros
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < width; j++) {
                board[i][j] = 0;
                // fill empty
                temp[0] = i;
                temp[1] = j;
                empty.push_back(temp);
            }
        }
    }
    Board() {
        width = 4;
        height = 4;
        score = 0;
        board.resize(width, vector<int>(height));
        empty.resize(0, vector<int>(2));
        vector<int> temp(2);
        // fill with zeros
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < width; j++) {
                board[i][j] = 0;
                // fill empty
                temp[0] = i;
                temp[1] = j;
                empty.push_back(temp);
            }
        }
    }

    // getters
    int getWidth();
    int getHeight();
    int getLoc(int x, int y);
    int getScore();
    int getEmptySize();

    // setters
    void setLoc(int x, int y, int n);
    void setScore(int s);

    // direction
    bool up(); 
    bool left();
    bool right();
    bool down();

    // other
    void fill(int n);
    void print();
    void add(bool b);
    bool noMoves();

    private:
    void updateEmpty();
    int width;
    int height;
    int score;
    vector<vector<int>> board;
    vector<vector<int>> empty;
};