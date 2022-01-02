
/*
Given a string, find the length of the longest repeating subsequence such that 
the two subsequences don’t have same string character at the same position, 
i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string. 
*/

#include <iostream>
#include <string>
using namespace std;
int dp[1001][1001];
int lrs(string s) {
    int x = s.length();
    memset(dp, 0, sizeof dp);
    for (int i=1; i <=x; i++) {
        for (int j=1; j<=x ; j++) {
            if(s[i-1] == s[j-1] && i != j) {
                dp[i][j] = 1+dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[x][x];
}

string printLRS(string s) {
    string ans;
    int i = s.length();
    int j = s.length();
    while (i > 0 && j > 0) {
        if(s[i-1] == s[j-1] && i!=j) {
            ans = s[i-1]+ans;
            i--;
            j--;
        } else {
            if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    return ans;
}

 int main() {
     cout<<lrs("aabebcdd")<<endl;
     cout<<printLRS("aabebcdd")<<endl;
     cout<<lrs("axxxy")<<endl;
     cout<<printLRS("axxxy")<<endl;
     return 0;
 }