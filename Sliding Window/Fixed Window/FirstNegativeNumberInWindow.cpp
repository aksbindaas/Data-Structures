/*
Given an array and a positive integer k, find the first negative integer for each window(contiguous subarray) of size k. 
If a window does not contain a negative integer, then print 0 for that window.
Input : arr[] = {-8, 2, 3, -6, 10}, k = 2
Output : -8 0 -6 -6
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

Input : arr[] = {12, -1, -7, 8, -15, 30, 16, 28} , k = 3
Output : -1 -1 -7 -15 -15 0
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve(vector<int> arr, int k) {
    int n  = arr.size();
    queue<int>ans;
    int i = 0, j = 0;
    while (j < n) {
        if(arr[j] < 0) {
            ans.push(arr[j]);
        }
        if(j-i+1 < k) {
            j++;
        } else {
            if(ans.empty()) {
                cout<<0<<" ";
            } else {
                cout<<ans.front()<<" ";
                if(arr[i] == ans.front()) {       
                    ans.pop();
                }
            }
            i++;
            j++;
        }
    }
    cout<<endl;
}

int main() {
    solve({12, -1, -7, 8, -15, 30, 16, 28}, 3);
    solve({-8, 2, 3, -6, 10}, 2);
    return 0;
}