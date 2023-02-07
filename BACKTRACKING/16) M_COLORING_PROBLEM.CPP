// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/m-coloring-problem_981273

#include <bits/stdc++.h> 
using namespace std ;

bool isValidToColor(int node,vector<int> adj[],int col,int color[]){
    vector<int> nodeAdjacents = adj[node] ;
    for(auto it:nodeAdjacents){
        if(color[it] == col) return false ;
    }
    return true ;
}

bool solve(int node , vector<int> adj[] , int m , int n,int color[]){
    // BASE CASE 
    // IF IT IS ABLE TO COLOR ALL NODES THEN RETURN TRUE 
    if(node == n) return true ;

    // TRY ALL COLORS WITH ALL NODES
    for(int i=1; i<=m ; i++){
        if(isValidToColor(node,adj,i,color)){
            color[node] = i ;
            if(solve(node+1,adj,m,n,color)) return true ;
            else color[node] = 0 ;
        }
    }
    // AT LAST IF COLORING IS NOT POSSIBLE 
    return false ;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    // CREATING GRAPH
    vector<int> adj[mat.size()] ;
    for(int i=0 ; i<mat.size() ; i++){
        for(int j=0 ; j<mat[0].size() ; j++){
            if(mat[i][j] == 1){
                adj[i].emplace_back(j) ;
                adj[j].emplace_back(i) ;
            }
        }
    }
    int color[mat.size()] = {0} ;
    if(solve(0,adj,m,mat.size(),color)) return "YES" ;
    else return "NO" ;
}

int main(){
    int test ; cin >> test ;
    while(test--){
        int n , m ;
        cin >> n >> m ;
        vector<vector<int>> mat(n,vector<int>(n)) ;
        for(int i=0 ; i<n ; i++){
          for(int j=0 ; j<n ; j++) cin >> mat[i][j] ;
        }
        cout << graphColoring(mat,m) << endl ;
    }
    return 0 ;
}
