/*
Print all permutations of a string keeping the sequence but changing cases.
Examples: 
Input : ab
Output : AB Ab ab aB
Input : ABC
Output : abc Abc aBc ABc abC AbC aBC ABC
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void helper(string ip, string op, vector<string> &ans) {
    if(ip.length() == 0) {
        ans.push_back(op);
        return;
    }
    
    if(isalpha(ip[0])) {
        string op1 = op;
        string op2 = op;
        op1.push_back(toupper(ip[0]));
        op2.push_back(tolower(ip[0]));
        ip.erase(ip.begin());
        helper(ip, op1, ans);
        helper(ip, op2, ans);
    } else {
        string op1 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin());
        helper(ip, op1, ans);
        return;
    }
   
    
}

void permute(string ip) {
    vector<string>ans;
    helper(ip, "", ans);
    for (auto it: ans) {
        cout<<it<<" ";
    }
    cout<<endl;
}

int main() {
    permute("a1b2");
    return 0;
}