#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void subsetsum2(int ind,vector<int>ds,vector<vector<int>>&ans,vector<int>&nums){
    ans.emplace_back(ds);
    for(int i=ind;i<nums.size();i++){
        if(i!=ind && nums[i] == nums[i-1]) continue;
        ds.emplace_back(nums[i]);
        subsetsum2(i+1,ds,ans,nums);
        ds.pop_back();
    }
}

int main()
{
    int n ; cin >> n ;
    vector<int>nums(n) ;
    for(int i=0 ; i<n ; i++) cin >> nums[i] ;
    vector<vector<int>>ans;
    vector<int>ds;
    subsetsum2(0,ds,ans,nums);
    for(auto vctr:ans){
        for(auto it:vctr){
            cout << it << " ";
        }
        cout << endl;
    }
}
