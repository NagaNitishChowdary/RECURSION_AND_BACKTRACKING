#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void perm(int ind,vector<int>&nums , vector<vector<int>>&ans){
    if(ind == nums.size()){
        ans.emplace_back(nums);
        return ;
    }
    for(int i=ind ; i<nums.size() ; i++){
        swap(nums[ind] , nums[i]);
        perm(ind+1,nums,ans);
        swap(nums[ind] , nums[i]);
    }
}

int main()
{
    int n ; cin >> n ;
    vector<int>nums(n); 
    for(int i=0 ; i<n ; i++) cin>>nums[i];
    vector<vector<int>>ans;
    perm(0,nums,ans);
    for(auto vctr:ans){
        for(auto it:vctr){
            cout << it << " " ;
        }
        cout << endl ;
    }
}
