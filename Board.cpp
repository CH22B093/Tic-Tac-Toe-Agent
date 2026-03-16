#include "Board.h"
#include "Game.h"
#include <iostream>
using namespace std;

Board::Board(){
    for (auto i{0};i<SIZE;++i){
        for (auto j{0};j<SIZE;++j){
            grid[i][j] = '_';
        }
    }
}

bool Board::isMovesLeft() const{
    for (auto i{0};i<SIZE;++i){
        for (auto j{0};j<SIZE;++j){
            if (grid[i][j] == '_')return true;
        }
    }
    return false;
}

int Board::evaluate(char ai_player,char human_player) const {
    // Rows and columns
    for (auto i{0};i<SIZE;++i){
        if (grid[i][0] != '_' && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]){
            if (grid[i][0] == ai_player)return 10;
            if (grid[i][0] == human_player) return -10;
        }
        if (grid[0][i] != '_' && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]){
            if (grid[0][i] == ai_player)return 10;
            if (grid[0][i] == human_player) return -10;
        }
    }
    
    // Diagonals
    if (grid[0][0] != '_' && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
        if (grid[0][0] == ai_player)return 10;
        if (grid[0][0] == human_player)return -10; 
    }
    if (grid[0][2] != '_' && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
        if (grid[0][2] == ai_player)return 10;
        if (grid[0][2] == human_player)return -10;
    }
    return 0;
}
void Board::print() const{
    std::cout<<"\n";
    for (auto i{0};i<SIZE;++i){
        for (auto j{0};j<SIZE;++j){
            std::cout<<grid[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}