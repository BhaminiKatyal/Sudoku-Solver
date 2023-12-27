#include <iostream>
using namespace std ;
#include <vector>

bool isValid(int i, int j, vector<vector<char>>& board, char num){
        for (int row = 0; row<9; row++){
            if (board[row][j]==num) return false ;
        }
        for (int col = 0; col<9; col++){
            if (board[i][col]==num) return false ;
        }
        for (int row = 3*(i/3); row<((i/3)+1)*3; row++){
            for (int col = 3*(j/3); col<((j/3)+1)*3; col++){
                if (board[row][col]==num) return false ;
            }
        }
        return true ;
    }

bool solveSudoku(vector<vector<char>>& board, int i){
        for (; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j]=='.'){
                    for (char num = '1'; num<='9'; num++){
                        if (isValid(i, j, board, num)) {
                            board[i][j]=num ;
                            if (solveSudoku(board, i)) return true ;
                            board[i][j] = '.' ;
                        }
                    }
                    if (board[i][j]=='.') return false ;
                }
            }
        }
        return true ;
    }

int main(){
    vector<vector<char>> board(9, vector<char>(9)) ;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cin>>board[i][j] ;
        }
    }
    solveSudoku(board, 0) ;
    cout << "---------------------" << endl;
    for (int i = 0; i < 9; i++) {
        if (i > 0 && i % 3 == 0) {
            cout << "---------------------" << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j > 0 && j % 3 == 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
    return 0;
}

