// PROBLEM LINK --- https://leetcode.com/problems/sudoku-solver/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board,int row,int col,char c){
    for(int i=0 ; i<9 ; i++){
        if(board[row][i] == c) return false;
        if(board[i][col] == c) return false;
        if(board[3*(row/3)+i/3][3*(col/3)+(i%3)] == c) return false;
    }
    return true ;
}

bool solveSoduku(vector<vector<char>> &board){
    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            if(board[i][j] == '.'){
                for(char c='1'; c<='9' ; c++){
                    if(isValid(board,i,j,c)==true){
                        board[i][j] = c ;
                        if(solveSoduku(board) == true) return true ;
                        else board[i][j] = '.' ;
                    }
                }
                return false;
            }
        }
    }
    return true ;
}

int main()
{
    vector<vector<char>> board(9,vector<char>(9,0));
    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            cin >> board[i][j] ;
        }
    }
    solveSoduku(board) ;
    for(auto vctr:board){
        for(auto it:vctr){
            cout << it << " " ;
        }
        cout << "\n" ;
    } 
}
