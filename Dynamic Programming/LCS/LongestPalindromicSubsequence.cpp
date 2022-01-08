/*
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or 
no elements without changing the order of the remaining elements.
*/

#include <iostream>
#include <string>
#include <algorithm>
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

int lcs(int m , int n , string s1, string s2) {
    if(m == 0 || n== 0) {
        return 0;
    }
    if(s1[m-1] == s2[n-1]) {
        return 1+ lcs(m-1, n-1, s1, s2);
    } else {
        return max(lcs(m-1, n , s1, s2), lcs(m, n-1, s1, s2));
    }
}

int main() {
    string s1 = "agbcba" , s2;
    s2 = s1;
    reverse(s1.begin(), s1.end());
    cout<<lcs(s1)<<endl;
    cout<<lcs(s1.length(), s1.length(), s1, s2)<<endl;

    s1 = "BBABCBCAB";
    s2 = s1;
    reverse(s1.begin(), s1.end());
    cout<<lcs(s2)<<endl;
    cout<<lcs(s1.length(), s1.length(), s1, s2)<<endl;
    
}