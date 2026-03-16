#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "MinimaxAi.h"

class Game{
    public: 
        Board board;
        MinimaxAI ai;
        void play();
};
#endif