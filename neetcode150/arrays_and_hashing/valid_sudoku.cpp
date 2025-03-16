#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool issafe(vector<vector<char>>& board, int i, int j, char c){
        int row = 3*(i/3), col = 3*(j/3);
        for(int k=0; k<9; k++){
            if(board[row+k/3][col+k%3]==c) return false;
            if(board[i][k]==c) return false;
            if(board[k][j]==c) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    char c = board[i][j];
                    board[i][j] = '.';
                    if(!issafe(board, i, j, c)) return false;
                    board[i][j] = c;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                
                pair<int, int> squareKey = {r / 3, c / 3};

                if (rows[r].count(board[r][c]) || cols[c].count(board[r][c]) || squares[squareKey].count(board[r][c])) {
                    return false;
                }

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[squareKey].insert(board[r][c]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9,0), cols(9,0), squares(9,0);
        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c]!='.'){
                    int val = board[r][c]-'0';
                    if((rows[r] & 1<<val) || (cols[c] & 1<<val) ||
                    (squares[3*(r/3) + c/3] & 1<<val)) return false;
                    rows[r] |= 1<<val;
                    cols[c] |= 1<<val;
                    squares[3*(r/3) + c/3] |= 1<<val;
                }
            }
        }
        return true;
    }
};