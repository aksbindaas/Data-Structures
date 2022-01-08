
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

int lrs(int m , int n , string s1, string s2){
    if(m == 0 || n == 0) {
        return 0;
    }
    if(s1[m-1] == s2[n-1] && m != n) {
        return 1+lrs(m-1, n-1, s1, s2);
    } else {
        return max(lrs(m-1, n, s1, s2), lrs(m, n-1, s1, s2));
    }
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
     string s1 = "aabebcdd";
     cout<<lrs(s1)<<endl;
     cout<<lrs(s1.length(), s1.length(), s1, s1)<<endl;
     cout<<printLRS(s1)<<endl;
     string s2 = "axxxy";
     cout<<lrs(s2)<<endl;
     cout<<lrs(s2.length(), s2.length(), s2, s2)<<endl;
     cout<<printLRS(s2)<<endl;
     return 0;
 }