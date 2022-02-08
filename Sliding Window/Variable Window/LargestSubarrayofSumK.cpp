/*
Given an array arr[] of size n containing integers. 
The problem is to find the length of the longest sub-array having sum equal to the given value k.
Input : arr[] = { 10, 5, 2, 7, 1, 9 }, 
            k = 15
Output : 4
The sub-array is {5, 2, 7, 1}.

Input : arr[] = {-5, 8, -14, 2, 4, 12},
            k = -5
Output : 5
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(vector<int> arr, int k) {
    int i = 0, j = 0;
    int n  = arr.size();
    int sum = 0;
    unordered_map<int, int> mp;
    int ws = INT_MIN;
    for (int i = 0; i<n ; i++) {
        sum += arr[i];

        if (sum == k)
             ws = i + 1;
 

        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }

        if(mp.find(sum -k) != mp.end()) {
            ws = max(ws, i-mp[sum-k]);
        }
    }

    ws = ws != INT_MIN ? ws : 0;
    cout<<"Largest Window Size "<<ws<<endl;
}

int main() {
    solve({10, 5, 2, 7, 1, 9}, 15);
    solve({-5, 8, -14, 2, 4, 12}, -5);
    solve({10, 15, -5, 15, -10, 5}, 20);
    solve({1, -1, 3, 2, -2, -8, 1, 7 , 10, 23}, 0);
    solve({-7, -11, -3, -7, 4, 15, -13, 18, -10, -10}, 23);
    return 0;
}
