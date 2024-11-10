#include<bits/stdc++.h>
using namespace std;

bool is_safe(int i, int j, char num, vector<vector<char>>& board){
    for(int a=0; a<9; a++){
        if(board[a][j]==num || board[i][a]==num) return false;
        if(board[3*(i/3) + a/3][3*(j/3) + a%3]==num) return false;
    }
    return true;
}
bool solve(vector<vector<char>>& board){
    for(int r=0; r<9; r++){
        for(int c=0; c<9; c++){
            if(board[r][c]=='.'){
                for(int num=1; num<=9; num++){
                    if(is_safe(r,c,'0'+num,board)){
                        board[r][c] = '0'+num;
                        if(solve(board)) return true;
                        else board[r][c] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
    return;
}