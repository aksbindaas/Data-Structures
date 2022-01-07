/*
Given a value V and array coins[] of size M, 
the task is to make the change for V cents, 
given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. 
Find the minimum number of coins to make the change. If not possible to make change then return -1.

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents

*/

#include<iostream>
#include<vector>
using namespace std;

int minCoins(vector<int> coins, int sum) {
    int size = coins.size();
    vector<vector<int>>t (size+1, vector<int>(sum+1, INT_MAX-1));
    //first row is initialised with INT_MAX -1
    // first column
    for (int i= 1; i<=size; i++) {
        t[i][0] = 0;
    }
    
    //unbounded knapsack code
    for (int i=1; i<=size;i++) {
        for (int j=1; j<=sum; j++) {
            if(coins[i-1]<=j) {
                t[i][j] = min(t[i-1][j], 1+t[i][j-coins[i-1]]);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    // for (auto oneD : t) {
    //     cout<<endl;
    //     for (auto val : oneD) {
    //         if(val != INT_MAX-1)
    //             cout<<val<<" ";
    //         else {
    //             cout<<"/"<<" ";
    //         }
    //     }
    // }
    // cout<<endl;
    return (t[size][sum] != INT_MAX -1) ? t[size][sum] : -1;
}

int minCoins(vector<int> coins, int n, int target) {
    //target 0 coins required.
    if(target==0) return 0;
    int res = INT_MAX-1;
    for (int k=0; k<n; k++) {
        if(coins[k] <= target) {
            int temp = 1+minCoins(coins, n, target-coins[k]);
              res = min(res, temp);
        }
    }
    return res;
}

int main() {
    cout<<minCoins({9,6,5,1}, 11)<<endl; 
    vector<int>a({9,6,5,1});
    cout<<minCoins(a,a.size(),11)<<endl; 

}