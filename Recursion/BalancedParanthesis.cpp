/*
Given an integer N representing the number of pairs of parentheses, 
the task is to generate all combinations of well-formed(balanced) parentheses.
*/

#include<iostream>
#include <string>
#include <vector>

using namespace std;

void helper(string s, int open, int close,vector<string>& ans) {
    if(open < 0 || close < 0) {
        return;
    }
    if(open == 0 && close == 0) {
        ans.push_back(s);
        return;
    }
    helper(s+"(", open -1, close, ans);
    if(open < close)
    helper(s+")", open, close-1, ans);
}

void solve(int n ) {
    vector<string> ans;
    helper("", n, n, ans);
    for (auto it: ans) {
        cout<<it<<" ";
    }
}

int main() {
    solve(3);
    return 0;
}