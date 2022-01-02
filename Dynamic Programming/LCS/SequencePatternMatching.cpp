/*
Sequence Pattern Matching
Return true is a is subsequence of string b otherwise return false;
*/
#include <iostream>
#include <string>
using namespace std;

int isLCS(string s, string t) {
    int x = s.length(), y = t.length();
    int dp[x+1][y+1];
    memset(dp, 0, sizeof dp);
    for (int i=1; i <=x; i++) {
        for (int j=1; j<=y ; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return (dp[x][y] == x);
}

int main() {
    string a = "AXY", b = "ADXCPY";
    cout<<isLCS(a, b)<<endl;
}