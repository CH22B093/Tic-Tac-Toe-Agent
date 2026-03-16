#ifndef MINIMAXAI_H
#define MINIMAXAI_H
// using namespace std;

#include "Board.h"
#include <utility>

class MinimaxAI{
    public:
        char AI_player;
        char human_player;

        MinimaxAI();
        int minimax(Board &board,bool isMax,int alpha,int beta,int depth);
        std::pair<int,int> find_best_move(Board &board);
};
#endif