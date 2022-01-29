/*
Given a string S. The task is to print all permutations of a given string in lexicographically sorted order.
Example 1:
Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
*/

#include<iostream>
#include<set>
#include<string>
using namespace std;

void helper(string s, int l, int r, set<string> &ans) {
    if(l == r) {
        ans.insert(s);
        return;
    }
    for (int i= l; i<=r; i++) {
        swap(s[i], s[l]);
        helper(s, l+1, r, ans);
        swap(s[i], s[l]);
    }
}

void solve(string s) {
    set<string> ans;
    helper(s, 0, s.length()-1, ans);
    for (auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {
    solve("ABC");
    return 0;
}