#include "Game.h"
#include <iostream>
using namespace std;

void Game::play(){
    cout<<"Welcome to Tic-Tac-Toe!\n";
    while (human_player != 'O' && human_player != 'X'){
        cout<<"Select your symbol (O or X): ";
        cin>>human_player;
        human_player = toupper(human_player);
    }
    AI_player = (human_player == 'O')?'X':'O';
    ai.setPlayers(AI_player,human_player);

    while (true){
        board.print();
        int r,c;
        cout<<"Enter row and column (0-2): ";
        cin>>r>>c;

        if (r < 0 || r > 2 || c < 0 || c > 2 || board.grid[r][c] != '_'){
            cout<<"Invalid move!\n";
            continue;
        }
        board.grid[r][c] = human_player;

        if (board.evaluate(AI_player,human_player) == -10){
            board.print();
            cout<<"You win!\n";
            break;
        }
        if (!board.isMovesLeft()){
            board.print();
            cout<<"Draw!\n";
            break;
        }

        auto [aiR,aiC] = ai.find_best_move(board);
        board.grid[aiR][aiC] = AI_player;
        cout<<"AI plays: "<<aiR<<" "<<aiC<<"\n";

        if (board.evaluate(AI_player,human_player) == 10){
            board.print();
            cout<<"AI wins!\n";
            break;
        }

        if (!board.isMovesLeft()){
            board.print();
            cout<<"Draw!\n";
            break;
        }
    }
}