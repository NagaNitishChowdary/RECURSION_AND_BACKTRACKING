#include<bits/stdc++.h>
using namespace std;

void findCombination(int ind,int target,vector<int>&candidates,vector<vector<int>>&ans,vector<int>&ds){
    if(ind==candidates.size()){
        if(target==0){
            ans.emplace_back(ds);
        }
        return ;
    }

    // PICKING THE ELEMENTS
    if(candidates[ind]<=target){
        ds.emplace_back(candidates[ind]);
        findCombination(ind,target-candidates[ind],candidates,ans,ds);
        ds.pop_back();
    }
    findCombination(ind+1,target,candidates,ans,ds);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>ds;
    findCombination(0,target,candidates,ans,ds);
    return ans;
}

int main()
{
    int n; cin>>n;
    vector<int>knnc;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        knnc.emplace_back(k);
    }
    int target; cin>>target;
    vector<vector<int>>result;
    result=combinationSum(knnc,target);
    for(auto vctr:result){
        for(auto it:vctr){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
}
