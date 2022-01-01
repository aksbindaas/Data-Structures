/*
Given two strings str1 and str2, the task is to find the length of the shortest string that has both 
str1 and str2 as subsequences.
*/
#include <iostream>
#include <string>
using namespace std;
int dp[101][101];
int lcs(string s, string t) {
    int x = s.length();
    int y = t.length();
    for (int i=1; i<=x; i++) {
        for (int j = 1; j<=y; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[x][y];
}

string PrintShortestCommonSubsequence(string s, string t) {
    int x = s.length(), y = t.length();
    int i = x, j = x;
    string ans;
    while(i > 0 && j > 0) {
        if(s[i-1] == t[j-1]) {
            ans = s[i-1]+ans;
            i--;
            j--;
        } else {
            if(dp[i][j-1] > dp[i-1][j]) {
                ans = t[j-1]+ans;
                j--;
            } else {
                ans = s[i-1]+ans;
                i--;
            }
        }
    }
    while (i!= 0) {
        ans = s[--i]+ans;
    }
    while (j != 0) {
        ans = t[--j]+ans;
    }

    return ans;
}

int ShortestCommonSubsequenceLength(string s, string t) {
    return s.length()+t.length() - lcs(s, t);
}
int main() {
    string s = "cab", t = "abac";
    memset(dp, 0, sizeof dp);
    cout<<ShortestCommonSubsequenceLength(s, t)<<endl;
    cout<<PrintShortestCommonSubsequence(s, t)<<endl;
}