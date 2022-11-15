// FIND ALL UNIQUE COMBINATIONS WHOSE SUM EQUAL TO TARGET
// EACH ELEMENT IN THE GIVEN VECTOR MUST BE USED ONLY ONCE
// THE SOLUTION SET MUST NOT CONTAIN DUPLICATE ELEMENTS

#include<bits/stdc++.h>
using namespace std;

void findCombination(int ind ,int target , vector<int>&candidates,vector<vector<int>>&ans,vector<int>&ds){
    if(target == 0){ ans.emplace_back(ds);
        return ;
    }

    for(int i=ind ; i<candidates.size() ; i++){
        if(i > ind && candidates[i] == candidates[i-1]) continue ;
        if(candidates[i] > target) break;
        ds.push_back(candidates[i]);
        findCombination(i+1,target-candidates[i],candidates,ans,ds);
        ds.pop_back();
    }

}

vector<vector<int>> combinationSum(vector<int>&candidates,int target){
    sort(candidates.begin(),candidates.end());
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
    return 0 ;
}
