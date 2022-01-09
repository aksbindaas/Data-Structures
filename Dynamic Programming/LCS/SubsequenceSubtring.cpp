/*
Substring - Subsequence problem 
Find the longest subsequence X of a string A which is a substring Y of a string B.
*/
#include <iostream>
#include <string>
using namespace std;

int solve(string s, string t) {
    int n = s.length(), m = t.length();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof dp);
    int ans = 0;
    int col = 0, row = 0;
    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
            } else {
                dp[i][j] = dp[i-1][j];
            }
            if(ans < dp[i][j]) {
                ans = dp[i][j];
                col = j;
                row = i;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    string str;
    while (dp[row][col] != 0) {
        str = t[col-1] + str;
        row--;
        col--;
    }
    cout<<"Maximum possible Subsequence of string X which is Substring of Y -> "<<str<<endl;
    return ans;
}

int main() {

    cout<<solve("ABCD", "BACDBDCD")<<endl;
  
    return 0;
}