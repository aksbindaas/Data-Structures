/*
Palindrome Partitioning 
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for a palindrome partitioning of a given string. For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. If a string is a palindrome, then minimum 0 cuts are needed. 
If a string of length n containing all different characters, 
then minimum n-1 cuts are needed. 
*/
#include <iostream>
#include <string>
using namespace std;
int t[1001][1001];

bool isPalindrom (string s , int i, int j) {
    while (i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string str, int i , int j ) {
    if(i>=j || isPalindrom(str, i, j)) {
        return 0;
    }
    if(t[i][j] != -1) {
        return t[i][j];
    }
    int mn = INT_MAX;
    int left = 0, right = 0;
    for (int k = i; k < j; k++) {
        if(t[i][k] != -1) {
            left = t[i][k];
        } else {
            left = t[i][k] = solve(str, i, k);
        }

        if(t[k+1][j] != -1) {
            right = t[k+1][j];
        } else {
            right = t[k+1][j] = solve(str, k+1, j);
        }
        mn = min(mn, 1+left+right);
    }
    return t[i][j] = mn;
}

int main() {
    string str = "abcde";
    memset(t, -1, sizeof t);
    cout<<solve(str, 0, str.length()-1)<<endl;

    str = "ababbbabbababa";
    memset(t, -1, sizeof t);
    cout<<solve(str, 0, str.length()-1)<<endl;

}