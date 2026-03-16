#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "MinimaxAi.h"

class Game{
    public: 
        char AI_player;
        char human_player;
        Board board;
        MinimaxAI ai;
        void play();
};
#endif