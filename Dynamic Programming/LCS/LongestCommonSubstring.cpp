#include <iostream>
#include<string>
#include <vector>
using namespace std;

int longestCommonSubstring(string S1, string S2) {
    int m = S1.length();
    int n = S2.length();
    int dp[m+1][n+1];
    memset(dp, 0, sizeof dp);
    int max_so_far = INT_MIN;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if(S1[i-1] == S2[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            max_so_far = max(max_so_far, dp[i][j]);
        }
    }
    return max_so_far;
}

int longestCommonSubstringRec(string s1, string s2, int m, int n, int count, vector<vector<int>> t) {
    cout<<count<<" "<<s1.substr(0,m)<<" "<<s2.substr(0,n)<<endl;
    if(m==0 || n == 0) {
        return count;
    }
    if(t[m][n] != 0) {
        return t[m][n];
    }
    int lcsCount1 = count;
    if(s1[m-1] == s2[n-1]) {
         lcsCount1  = t[m][n] = longestCommonSubstringRec(s1, s2, m-1, n-1, count+1, t);
    } 
    int lcsCount2 = max(longestCommonSubstringRec(s1, s2, m-1, n, 0, t),longestCommonSubstringRec(s1, s2, m, n-1, 0, t));
    return t[m][n] = max(lcsCount1,lcsCount2);
}

int main() {
    string S1 = "adac";
    string S2 = "adacdac";
    cout<<longestCommonSubstring(S1, S2)<<endl;
    // S1 = "";
    // S2 = "";
    vector<vector<int>> t(S1.length()+1, vector<int>(S2.length()+1));
    cout<<longestCommonSubstringRec(S1, S2,  S1.length(), S2.length(),0, t)<<endl;
}