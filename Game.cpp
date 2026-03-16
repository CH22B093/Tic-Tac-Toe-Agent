#include "Game.h"
#include <iostream>
using namespace std;

void Game::play(){
    cout<<"You are O. AI is X.\n";

    while (true){
        board.print();
        int r,c;
        cout<<"Enter row and column (0-2): ";
        cin>>r>>c;

        if (r < 0 || r > 2 || c < 0 || c > 2 || board.grid[r][c] != '_'){
            cout<<"Invalid move!\n";
            continue;
        }
        board.grid[r][c] = 'O';

        if (board.evaluate() == -10){
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
        board.grid[aiR][aiC] = 'X';
        cout<<"AI plays: "<<aiR<<" "<<aiC<<"\n";

        if (board.evaluate() == 10){
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