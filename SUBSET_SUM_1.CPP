#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void subsetsum(int ind,int n,int arr[],vector<int>ds,int sum1,vector<int>&ans){
    if(ind == n){
        //for(auto it:ds) cout << it << " " ;
        //cout << endl ; return ;
        ans.emplace_back(sum1);
        //cout << sum1 << " " ;
        return ;
    }
    ds.emplace_back(arr[ind]);
    subsetsum(ind+1,n,arr,ds,sum1+arr[ind],ans);
    ds.pop_back();
    subsetsum(ind+1,n,arr,ds,sum1,ans);
}

int main() {
    int n ; cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    vector<int>ds;
    vector<int>ans ;
    subsetsum(0,n,arr,ds,0,ans);
    sort(ans.begin(),ans.end());
    for(auto it:ans) cout << it << " " ;
    cout << endl ;
    return 0 ;
}
