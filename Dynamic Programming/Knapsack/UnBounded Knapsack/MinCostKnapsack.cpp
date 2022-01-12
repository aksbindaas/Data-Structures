/*
Minimum cost to fill given weight in a bag
Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
2. It may be assumed that there is infinite supply of all available packet types.
*/
#include <iostream>
#include <vector>
using namespace std;

int minCost(vector<int>cost, int W) {
    vector<int>val;
    vector<int>wt;
    for (int i=0; i<cost.size(); i++) {
        if(cost[i] != -1) {
            val.push_back(cost[i]);
            wt.push_back(i+1);
        }
    }
    int n = val.size();
    int dp[n+1][W+1];
    memset(dp, 0, sizeof dp);
    for(int i=0; i<=W; i++) {
        dp[0][i] = INT_MAX;
    }
    for (int i = 1 ; i<=n; i++) {
        for (int j = 1; j<=W; j++) {
            if(wt[i-1] <= j) {
                 int temp = dp[i][j-wt[i-1]] != INT_MAX ? val[i-1]+dp[i][j-wt[i-1]]: INT_MAX; 
                 dp[i][j] = min(dp[i-1][j], temp);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // for (int i=0; i<=n; i++) {
    //         for (int j = 0; j<=W; j++) {
    //             cout<<dp[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    return dp[n][W];
}

int main() {
    cout<<minCost({20, 10, 4, 50, 100}, 5)<<endl;
    cout<<minCost({55, 48, 13, 46, 54, 76, 28, 99, 33, 8, 75, 6, 7, 58, 48, 89, 1, 52}, 2)<<endl;
    cout<<minCost({-1, 25, 78, 40, 77, 66, 13, 96, 76, 92, 11, 67, 11, 94}, 29)<<endl;
    return 0;
}