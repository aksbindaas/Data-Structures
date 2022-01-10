/*
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.
*/
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int lis(vector<int>a, vector<int>b, int n, int m) {
    int dp[n+1][m+1];
    memset(dp, 0, sizeof dp);
    for (int i =1; i<=n; i++) {
        for (int j =1; j<=m; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = 1+ dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main() {
    vector<int> a {2, 10, 5, 1, 8, 6, 6, 6, 5};
    vector<int> b = a;
    sort(b.begin(), b.end());
    auto ip = unique(b.begin(), b.end());
    b.resize(distance(b.begin(), ip));
    cout<<lis(a, b, a.size(), b.size())<<endl;
    return 0;
}