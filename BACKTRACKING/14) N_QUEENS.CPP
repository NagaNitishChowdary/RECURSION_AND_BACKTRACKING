// PROBLEM LINK --- https://leetcode.com/problems/n-queens/

// FOR PLACING THE NEXT QUEEN IN THE COLUMN WE HAVE ONLY TO CHECK IN 3 DIMENSIONS 
// i.e LEFT ROW,LOWER DIAGONAL,UPPER DIAGONAL 
// LEFT ROW IS OF SIZE = N 

#include<bits/stdc++.h>
using namespace std;

void solve(int col , vector<string> &board , vector<vector<string>> &ans ,vector<int> &leftRow , vector<int> &upperDiagonal ,vector<int> &lowerDiagonal ,int n){
    if(col == n){
        ans.emplace_back(board);
        return ;
    }
    for(int row=0 ; row<n ; row++){
        if(leftRow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[n-1 + col-row] == 0){
            board[ row ][ col ] = 'Q' ;
            leftRow[ row ] = 1 ;
            upperDiagonal[ n-1 + col-row ] = 1 ;
            lowerDiagonal[ row+col ] = 1 ;
            solve(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
            board[row][col] = '.' ;
            leftRow[row] = 0 ;
            lowerDiagonal[row+col] = 0;
            upperDiagonal[n-1 + col-row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0 ; i<n ; i++) board[i] = s ;
    vector<int> leftRow(n,0) , upperDiagonal(2*n-1,0) , lowerDiagonal(2*n-1,0) ;
    solve(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
    return ans;
}

int main()
{
    int n ; cin >> n; 
    vector<vector<string>> ans1 ;
    ans1 = solveNQueens(n) ;
    for(auto vctr : ans1){
        for(auto it : vctr) {
            cout << it << "\n" ;
        }
        cout << endl ;
    }
}
