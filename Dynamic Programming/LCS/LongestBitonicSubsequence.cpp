/*
Given an array arr[0 … n-1] containing n positive integers, a subsequence of arr[] is called Bitonic if it is first increasing, then decreasing. Write a function that takes an array as argument and returns the length of the longest bitonic subsequence. 
A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty. 
Examples:

Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

Input arr[] = {12, 11, 40, 5, 3, 1}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 12, 11, 5, 3, 1)

Input arr[] = {80, 60, 30, 40, 20, 10}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 80, 60, 30, 20, 10)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LongestBitonicSubsequence(vector<int> nums) {
    int n = nums.size();
    vector<int>lis(n,1);
    vector<int>lds(n,1);

    //calculate lis
    for (int i = 1; i<n; i++) {
        for (int j = 0; j<i ;j++) {
            if(nums[j] < nums[i]) {
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }

    // calculate lds
    for (int i = n-2; i>=0; i--) {
        for (int j = n-1; j>i ;j--) {
            if(nums[j] < nums[i]) {
                lds[i] = max(lds[i], lds[j]+1);
            }
        }
    }

    int max_so_far = 0;
    for (int i = 0 ; i<n; i++) {
        max_so_far = max(max_so_far, lis[i]+lds[i] - 1);
    }
    return max_so_far;

}

int main() {
    cout<<LongestBitonicSubsequence({1, 2, 5, 3, 2})<<endl;
    cout<<LongestBitonicSubsequence({1, 11, 2, 10, 4, 5, 2, 1})<<endl;
    cout<<LongestBitonicSubsequence({12, 11, 40, 5, 3, 1})<<endl;
    cout<<LongestBitonicSubsequence({80, 60, 30, 40, 20, 10})<<endl;
    return 0;
}