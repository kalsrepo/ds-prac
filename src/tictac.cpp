//
//  tictac.cpp
//  practice-personal-laptop
//
//  Created by Kallol Banerjee on 10/24/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "tictac.hpp"

int board[3][3];

const int cross = 1;
const int zero = 0;

bool isWinner (int **board, int &win)
{
    bool isWinner = true;
    
    // check if any horizontal has all 0 or 1
    for (int i = 0; i < 3; i++) {
        int prev = board[i][0];
        for (int j = 0; j < 3; j++) {
            if (prev != board[i][j]) {
                isWinner = false;
                win = prev;
                break;
            }
        }
    }
    
    if (isWinner) {
        return true;
    }
    
    // check if any vertical has all 0 or 1
    isWinner = true;
    for (int i = 0; i < 3; i++) {
        int prev = board[0][i];
        for (int j = 0; j < 3; j++) {
            if (prev != board[i][j]) {
                isWinner = false;
                win = prev;
                break;
            }
        }
    }
    
    if (isWinner) {
        return true;
    }
    
    // check if diagonal increasing
    win = board[0][0];
    isWinner = ((board[0][0] == board[1][1]) ? ((board[1][1] == board[2][2]) ? true : false ) : false);
    
    if (isWinner) {
        return true;
    }
    
    // check the other diagonal
    win = board[0][2];
    isWinner = ((board[0][2] == board[1][1]) ? ((board[1][1] == board[2][0]) ? true : false ) : false);
    
    return isWinner;
}

