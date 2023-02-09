#include<bits/stdc++.h>
using namespace std ;

bool palindrome(int i,int n,string s){
  if(i >= n/2) return true ;
  if(s[i] != s[n-i-1]) return false ;
  palindrome(i+1,n,s) ;
}

void solve(){
    string s ; cin >> s ;
    cout << palindrome(0,s.size(),s) << endl ;
}

int main(int argc,char const *argv[]) {
    int testCases ; cin >> testCases ;
    while(testCases--) solve();
    return 0;  
}
