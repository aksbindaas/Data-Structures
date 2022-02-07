/*
Maximum of all subarrays of size k
Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;



void solve(vector<int> arr , int k) {
    int n = arr.size();
    std::deque<int> q(k);
    int i =0, j = 0;
    while (j < n) {
        // delete all back items from queue who is lower then current value
        while ((!q.empty()) && arr[j] >= arr[q.back()])
            q.pop_back();
        
        // insert current index
        q.push_back(j);
    
        if(j- i + 1 < k) {
            j++;
        } else {
            cout<<arr[q.front()]<<" ";
            // Remove the elements which are out of this window
             if(q.front() == i) {
               q.pop_front();
            }
            i++;
            j++;
        }
    }
    cout<<endl;
}

int main() {
    solve({1, 2, 3, 1, 4, 5, 2, 3, 6}, 3);
    solve({8, 5, 10, 7, 9, 4, 15, 12, 90, 13},4);
    solve({5,4,3,2,1}, 2);
    solve({1,2,3,4,5}, 1);
    solve({12, 1, 78, 90, 57, 89, 56 }, 3);
    return 0;
}