// PROBLEM LINK --- https://leetcode.com/problems/word-search/

#include<bits/stdc++.h>
using namespace std ;

bool solve(int i,int j,vector<vector<char>> &board,int n,int m,string word,string knnc,vector<vector<int>> &vis,int ind){
    // BASE CASE IF WORD IS FOUND THEN RETURN TRUE 
    if(ind == word.size()-1) return true ;
    // MARK THE LETTER AS VISITED IN VISITED MATRIX BECAUSE A LETTER CAN ONLY BE USED ONCE
    vis[i][j] = 1 ;

    // CHECK DOWN OF PRESENT LETTER FOR THE REQUIRED LETTER 
    if(i+1 < n && vis[i+1][j] == 0 && word[ind+1] == board[i+1][j]){
      if(solve(i+1,j,board,n,m,word,knnc+word[ind+1],vis,ind+1)) return true ;
    }

    // CHECK UP OF PRESENT LETTER FOR THE NEXT LETTER
    if(i-1 >= 0 && vis[i-1][j] == 0 && word[ind+1] == board[i-1][j]){
      if(solve(i-1,j,board,n,m,word,knnc+word[ind+1],vis,ind+1)) return true ;
    }

    // CHECK RIGHT OF PRESENT LETTER FOR THE NEXT LETTER 
    if(j+1 < m && vis[i][j+1] == 0 && word[ind+1] == board[i][j+1]){
      if(solve(i,j+1,board,n,m,word,knnc+word[ind+1],vis,ind+1)) return true ;
    }

    // CHECK LEFT OF PRESENT LETTER FOR THE NEXT LETTER
    if(j-1 >= 0 && vis[i][j-1] == 0 && word[ind+1] == board[i][j-1]){
      if(solve(i,j-1,board,n,m,word,knnc+word[ind+1],vis,ind+1)) return true ;
    }        

    vis[i][j] = 0 ;
    // IF NOT FOUND THEN RETURN FALSE
    return false ;
  }

  bool exist(vector<vector<char>>& board, string word) {
      // STORE STARTING LETTER OF WORD OCCURANCES IN THE VECTOR TO SEARCH EASILY
    vector<pair<int,int>> start ;
    int n = board.size() , m = board[0].size() ;
    for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<m ; j++){
        if(board[i][j] == word[0]) start.push_back({i,j}) ;
      }
    }

        // IF STARTING LETTER OF WORD IS NOT FOUND IN BOARD THEN RETURN FALSE
    int s = start.size() ;
    if(s == 0) return false ; 

        // RUN LOOP UNTIL THE WORD IS IDENTIFIED IN THE BOARD
    for(int i=0 ; i<s ; i++){
      vector<vector<int>> vis(n,vector<int>(m,0)) ;
      if(solve(start[i].first,start[i].second,board,n,m,word,to_string(word[0]),vis,0)) return true ;
    }

        // IF NOT FOUND RETURN FALSE
    return false ;
}

int main(){
    int t ; cin >> t ;
    while(t--){
        int n,m ; cin >> n >> m ;
        vector<vector<char>> board(n,vector<char>(m)) ;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++) cin >> board[i][j] ;
        }
        string word ; cin >> word ;
        cout << exist(board,word) << endl ;
    }
    return 0 ;
}
