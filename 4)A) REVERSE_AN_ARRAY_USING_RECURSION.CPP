#include<bits/stdc++.h>
using namespace std ;

void knnc(int i,int j,int arr[]){
  if(i >= j) return ;
  swap(arr[i] , arr[j]) ;
  knnc(i+1,j-1,arr) ;
}

void solve(){
    int n ; cin >> n ;
    int arr[n] ;
    for(int i=0 ; i<n ; i++) cin >> arr[i] ;
    knnc(0,n-1,arr) ;
    for(int i=0 ; i<n ; i++) cout << arr[i] << " " ;
    cout << endl ;
}

int main(int argc,char const *argv[]) {
    int testCases ; cin >> testCases ;
    while(testCases--) solve();
    return 0;  
}
