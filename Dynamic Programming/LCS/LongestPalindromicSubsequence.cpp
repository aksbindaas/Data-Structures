/*
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or 
no elements without changing the order of the remaining elements.
*/

#include <iostream>
#include <string>
using namespace std;

int lcs(string s) {
    int dp[2][1001];
    memset(dp, 0, sizeof dp);
    int x = s.length();
    for (int i = 1; i<=x ; i++) {
        for (int j = 1; j<=x; j++) {
            if(s[i-1] == s[x-j]) {
                dp[i%2][j] = 1+ dp[(i-1)%2][j-1];
            } else {
                dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
            }
        }
    }
    return dp[x%2][x];
}

int main() {
    cout<<lcs("agbcba")<<endl;
    cout<<lcs("BBABCBCAB")<<endl;
}