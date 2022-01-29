/*
Given an array arr[] of integers of size N that might contain duplicates, the task is to find all possible unique subsets.

Note: Each subset should be sorted.
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve(vector<int> in, vector<int> op, set<vector<int> >&ans) {
    if(in.size() == 0) {
        ans.insert(op);
        return;
    }

    vector<int> op1 = op;
    op1.push_back(in[0]);
    in.erase(in.begin());
    solve(in, op, ans);
    solve(in, op1, ans);
}
void AllSubsets(vector<int> in) {
    vector<int> op;
    set<vector<int> >ans;
    solve(in, op, ans);
    for (auto it= ans.begin(); it != ans.end(); it++) {
        cout<<"( ";
        for (auto it1 : *it) {
            cout<<it1<<" ";
        }
        cout<<") ";
    }
    cout<<endl;
}

int main() {
    vector<int> a({2,1,2});
    sort(a.begin(), a.end());
    AllSubsets(a);
    return 0;
}