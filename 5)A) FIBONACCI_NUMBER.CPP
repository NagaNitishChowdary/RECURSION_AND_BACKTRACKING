#include<bits/stdc++.h>
using namespace std ;

int fib(int n){
    if(n == 0 || n == 1) return n ;
    return fib(n-1) + fib(n-2) ; 
}

void solve(){
    int n ; cin >> n ; 
    cout << fib(n) << endl ;
}

int main(int argc,char const *argv[]) {
    int testCases ; cin >> testCases ;
    while(testCases--) solve();
    return 0;  
}
