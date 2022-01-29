/*
Given a string S find all possible subsequences of the string in lexicographically-sorted order.
Example 1:

Input : str = "abc"
Output: a ab abc ac b bc c
Explanation : There are 7 substrings that 
can be formed from abc.
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

void helper(string ip, string op, multiset<string> &ans) {
    if(ip.length() == 0) {
        if(op.length() != 0) {
            ans.insert(op);
        }
        return;
    }
    string op1 = op;
    op1.push_back(ip[0]);
    ip.erase(ip.begin());
    helper(ip, op, ans);
    helper(ip, op1, ans);
}

void solve(string s) {
    string op;
    multiset<string>ans;
    helper(s, op, ans);
    for (auto it = ans.begin(); it != ans.end(); ++it)
        cout << *it<<" ";
    cout<<endl;
}

int main() {
    solve("abc");
    solve("aab");
    return 0;
}