#ifndef MINIMAXAI_H
#define MINIMAXAI_H
// using namespace std;

#include "Board.h"
#include <utility>

class MinimaxAI{
    public:
        MinimaxAI();
        void setPlayers(char ai_player,char human_player);
        int minimax(Board &board,bool isMax,int alpha,int beta,int depth);
        std::pair<int,int> find_best_move(Board &board);
    private:
        char AI_player;
        char human_player;
};
#endif