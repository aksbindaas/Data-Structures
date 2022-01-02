/*
Minimum number of deletions and insertions to transform one string into another

Given two strings ‘str1’ and ‘str2’ of size m and n respectively. 
The task is to remove/delete and insert the minimum number of characters from/in str1 to transform it into str2. 
It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to 
some another point.
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

int MinInsertDeleteToConvert(string s, string t) {
    cout<<s<<" "<<t<<endl;
    cout<<"Min Deletion " << s.length() - lcs(s, t)<<endl;
    cout<<"Min Insertion " << t.length() - lcs(s, t)<<endl;
    return s.length()+t.length() - 2* lcs(s, t);
    
}
int main() {
    cout<<MinInsertDeleteToConvert("heap", "pea")<<endl;
    cout<<MinInsertDeleteToConvert("geeksforgeeks", "geeks")<<endl;
}