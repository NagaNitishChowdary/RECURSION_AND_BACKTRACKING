// PROBLEM LINK --- https://leetcode.com/problems/palindrome-partitioning/
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_799931
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

#include <bits/stdc++.h> 
using namespace std ;

bool isPalindrome(string s,int start ,int end){
    while(start <= end){
        if(s[start++] != s[end--]) return false ;
    }
    return true ;
}

void solve(int ind,vector<string> &path,vector<vector<string>> &ans,string s){
    if(ind == s.size()){
        ans.push_back(path) ;
        return ;
    }
    
    for(int i=ind ; i<=s.size() ; i++){
        if(isPalindrome(s,ind,i)){
            path.push_back(s.substr(ind,i-ind+1)) ;
            // HERE I+1 NOT INDEX+1     
            solve(i+1,path,ans,s) ;
            path.pop_back() ;
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans ;
    vector<string> path ; // PATH WILL BE STORING INDIVIDUAL SUB STRINGS
    solve(0,path,ans,s) ;
    return ans ;
}

int main(){
    int test ; cin >> test ;
    while(test--){
        string s ; cin >> s ;
        vector<vector<string>> ans = partition(s) ;
        for(auto it:ans){
          for(auto str:it) cout << str << " " ;
          cout << endl ;
        }
    }
    return 0 ;
}
