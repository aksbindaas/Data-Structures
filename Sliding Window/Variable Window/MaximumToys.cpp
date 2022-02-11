/*
Given an array arr[ ] of length N consisting cost of N toys and an integer K depicting the amount with you. 
Your task is to find maximum number of toys you can buy with K amount. 
Example 1:

Input: 
N = 7 
K = 50
arr[] = {1, 12, 5, 111, 200, 1000, 10}
Output: 4
Explaination: The costs of the toys 
you can buy are 1, 12, 5 and 10.

N = 3 
K = 100
arr[] = {20, 30, 50}
Output: 3
Explaination: You can buy all toys.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(vector<int>arr, int k) {
    sort(arr.begin(), arr.end());
    int count = 0;
    int i = 0;
    for (; i< arr.size(); i++) {
        count += arr[i];
        if(count > k) {
            break;
        }
    }
    
    cout<<"Maximum toy count "<<i<<endl;
}

int main() {
    solve({1, 12, 5, 111, 200, 1000, 10}, 50);
    solve({20, 30, 50}, 100);
    return 0;
}