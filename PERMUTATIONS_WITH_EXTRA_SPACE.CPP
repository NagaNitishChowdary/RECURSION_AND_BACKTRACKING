#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void perm(int freq[],vector<int>&nums,vector<int>ds){
    if(ds.size() == nums.size()){
        for(auto it:ds) cout << it << " ";
         cout << endl ; return ;
    }
    for(int i=0 ; i<nums.size() ; i++){
        if(!freq[i]){
            ds.emplace_back(nums[i]);
            freq[i] = 1;
            perm(freq,nums,ds) ;
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

int main()
{
    int n ; cin >> n ;
    vector<int>nums(n); 
    for(int i=0 ; i<n ; i++) cin>>nums[i];
    int freq[n] = {0};
    vector<int>ds;
    perm(freq,nums,ds);
}
