#include "MinimaxAi.h"
#include <algorithm>
using namespace std;

MinimaxAI::MinimaxAI(){
    AI_player = 'X';
    human_player = 'O';
}

int MinimaxAI::minimax(Board &board, bool isMax, int alpha,int beta,int depth){
    int score = board.evaluate();
    if (score == 10) return score - depth;
    if (score == -10)return score + depth;
    if (!board.isMovesLeft())return 0;
    if (isMax){
        int best = -1000;
        for (auto i{0};i<Board::SIZE;++i){
            for (auto j{0};j<Board::SIZE;++j){
                if (board.grid[i][j] == '_'){
                    board.grid[i][j] = AI_player;
                    best = max(best,minimax(board,false,alpha,beta,depth + 1));
                    board.grid[i][j] = '_';

                    alpha = max(alpha,best);
                    if (beta <= alpha)return best;
                }
            }
        }
        return best;
    }
    else{
        int best = 1000;
        for (auto i{0};i<Board::SIZE;++i){
            for (auto j{0};j<Board::SIZE;++j){
                if (board.grid[i][j] == '_'){
                    board.grid[i][j] = human_player;
                    best = min(best,minimax(board,true,alpha,beta,depth + 1));
                    board.grid[i][j] = '_';
                    beta = min(beta,best);
                    if (beta <= alpha)return best;
                }
            }
        }
        return best;
    }
}

pair<int,int> MinimaxAI::find_best_move(Board &board){
    int bestval = -1000;
    pair<int,int> bestMove = {-1,-1};

    for (auto i{0};i<Board::SIZE;++i){
        for (auto j{0};j<Board::SIZE;++j){
            if (board.grid[i][j] == '_'){
                board.grid[i][j] = AI_player;
                int moveval = minimax(board,false,-1000,1000,0);
                board.grid[i][j] = '_';
                if (moveval > bestval){
                    bestMove = {i,j};
                    bestval = moveval;
                }
            }
        }
    }
    return bestMove;
}