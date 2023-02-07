// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030

#include <bits/stdc++.h>
using namespace std;
    
bool isValid(int i,int j,int n){
    return i >= 0 && i < n && j >= 0 && j < n ;
}

void solve(int i,int j,vector<vector<int>> &m,int n,vector<string> &ans,string move,
    vector<vector<int>> &vis ){
    if(i == n-1 && j == n-1){
        ans.emplace_back(move) ;
        return ;
    }    
    
    // WE MUST RETURN ANSWER IN THE LEXICOGRAPHICAL ORDER
    // SO FIRST MOVE DOWN , LEFT , RIGHT THEN UP 
    
    // DOWN
    if(isValid(i+1,j,n) && vis[i+1][j] == 0 && m[i+1][j] == 1){
        vis[i][j] = 1 ;
        solve(i+1,j,m,n,ans,move+'D',vis) ;
        vis[i][j] = 0 ;
    }
    
    // LEFT
    if(isValid(i,j-1,n) && vis[i][j-1] == 0 && m[i][j-1] == 1){
        vis[i][j] = 1 ;
        solve(i,j-1,m,n,ans,move+'L',vis) ;
        vis[i][j] = 0 ;
    }
    
    // RIGHT
    if(isValid(i,j+1,n) && vis[i][j+1] == 0 && m[i][j+1] == 1){
        vis[i][j] = 1 ;
        solve(i,j+1,m,n,ans,move+'R',vis) ;
        vis[i][j] = 0 ;
    }
    
    // UP
    if(isValid(i-1,j,n) && vis[i-1][j] == 0 && m[i-1][j] == 1){
        vis[i][j] = 1 ;
        solve(i-1,j,m,n,ans,move+'U',vis) ;
        vis[i][j] = 0 ;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string > ans ;
    vector<vector<int>> vis(n,vector<int>(n,0)) ;
    if(m[0][0] == 1 && m[n-1][n-1] == 1) solve(0,0,m,n,ans,"",vis) ;
    return ans ;
}

int main() {
    int t ; cin >> t ;
    while (t--) {
        int n ; cin >> n ;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> m[i][j] ;
        vector<string> result = findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0) cout << -1 ;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
