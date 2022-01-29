/*
Given a string you need to print all possible strings that can be made by placing spaces (zero or one) i
n between them. The output should be printed in sorted increasing order of strings
*/
#include <iostream>
#include <string>
#include <set>

using namespace std;

void helper(string ip, string op, set<string> &ans) {
    if(ip.length() == 0) {
        ans.insert(op);
        return;
    }
    string op1 = op+" ";
    op1.push_back(ip[0]);

    string op2 = op;
    op2.push_back(ip[0]);

    ip.erase(ip.begin());
    helper(ip, op2, ans);
    helper(ip, op1, ans);
}

void permutation(string s) {
    set<string> ans;
    string op = s.substr(0,1);
    s.erase(s.begin());

    helper(s, op,ans);
    for (auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {
    permutation("ABC");
    return 0;
}