#ifndef BOARD_H
#define BOARD_H

class Board{
    public:
        static const int SIZE = 3;
        char grid[SIZE][SIZE];
        Board();
        bool isMovesLeft() const;
        int evaluate(char ai_player,char human_player) const;
        void print() const;
};
#endif