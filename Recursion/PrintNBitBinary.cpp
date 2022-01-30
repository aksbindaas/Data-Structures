/*
Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s 
than 0’s for any prefix of the number.
Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than 
or equal 1's than 0's
*/
#include <iostream>
#include<string>
#include<vector>
using namespace std;

void helper(string op, int n, int ones, int zeros, vector<string> &ans) {
    if(n==0) {
        if(ones >= zeros) {
            ans.push_back(op);
        }
        return;
    }

    helper(op+"1", n-1, ones+1, zeros, ans);
    if(ones > zeros)
    helper(op+"0", n-1, ones, zeros+1, ans);
}

void solve(int n) {
    vector<string> ans;
    helper("1", n-1, 1, 0, ans);
    for (auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {
    solve(2);
    solve(3);
    solve(4);
    return 0;
}