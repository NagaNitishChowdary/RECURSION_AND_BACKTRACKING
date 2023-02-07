// PROBLEM LINK --- https://leetcode.com/problems/permutation-sequence/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/find-kth-permutation/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/k-th-permutation-sequence_1112626

#include <bits/stdc++.h>
using namespace std;

string kthPermutation(int n, int k)
{
    int fact = 1;
    vector<int> numbers ;
    for(int i=1 ; i<n ; i++){
        fact *= i ;
        numbers.push_back(i) ;
    }
    numbers.push_back(n) ;
    string ans = "" ;
    k-- ; // index starts from 0 
    while(true){
        ans += to_string(numbers[k/fact]) ;
        numbers.erase(numbers.begin()+k/fact) ;
        if(numbers.size() == 0) break ;
        k = k%fact ;
        fact = fact/numbers.size() ;
    }
    return ans ;
}

int main()
{
    int t ; cin >> t ;
    while (t--){
        int n, k ;
        cin >> n >> k ;
        string ans = kthPermutation(n, k);
        cout << ans << endl ;
    }
    return 0;
}
