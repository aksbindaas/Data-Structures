/*
Minimum insertions or deletion to form a palindrome
Given string str, the task is to find the minimum number of characters to be inserted to convert it to a palindrome.
Before we go further, let us understand with a few examples: 
*/
#include <iostream>
#include <string>
using namespace std;

int lps(string s) {
      int x = s.length();
      int dp[x+1][x+1];
      memset(dp, 0, sizeof dp);
      for (int i=1; i <=x ; i++) {
          for (int j = 1; j<=x ; j++) {
              if(s[i-1] == s[x-j]) {
                  dp[i][j] = 1+dp[i-1][j-1];
              } else {
                  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
              }
          }
      }
      return dp[x][x];
  }
  
  int minInsert2ConvertPalindrom(string s) {
      return s.length() - lps(s);
  }
  int main() {
      cout<<minInsert2ConvertPalindrom("abcd")<<endl;
      cout<<minInsert2ConvertPalindrom("geeks")<<endl;
      return 0;
  }