/*
Given an array of integers. A subsequence of arr[] is called Bitonic if it is first increasing, then decreasing. 
Examples : 
 

Input : arr[] = {1, 15, 51, 45, 33, 
                   100, 12, 18, 9}
Output : 194
Explanation : Bi-tonic Sub-sequence are :
             {1, 51, 9} or {1, 51, 100, 18, 9} or
             {1, 15, 51, 100, 18, 9}  or 
             {1, 15, 45, 100, 12, 9}  or 
             {1, 15, 45, 100, 18, 9} .. so on            
Maximum sum Bi-tonic sub-sequence is 1 + 15 +
51 + 100 + 18 + 9 = 194   

Input : arr[] = {80, 60, 30, 40, 20, 10} 
Output : 210  
*/

#include <iostream>
#include <vector>
using namespace std;

int MaxSumBitonicSubSequence(vector<int>nums) {
    int n = nums.size();
    vector<int>MSIBS = nums;
    vector<int>MSDBS = nums;
    // calculate MSIBS
    for (int i = 1; i<n; i++) {
        for (int j=0; j <i ; j++) {
            if(nums[j] < nums[i]) {
                MSIBS[i] = max(MSIBS[i], MSIBS[j]+nums[i]);
            }
        }
    }

    // calculate MSDBS
    for (int i = n-2; i>=0; i--) {
        for (int j=n-1; j>i ; j--) {
            if(nums[j] < nums[i]) {
                MSDBS[i] = max(MSDBS[i], MSDBS[j]+nums[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0 ; i<n; i++) {
        ans = max(ans, MSDBS[i]+MSIBS[i]-nums[i]);
    }
    return ans;
}

int main() {
    cout<<MaxSumBitonicSubSequence({ 1, 15, 51, 45, 33, 100, 12, 18, 9 })<<endl;
    cout<<MaxSumBitonicSubSequence({1, 2, 5, 3, 2})<<endl;
    cout<<MaxSumBitonicSubSequence({1, 11, 2, 10, 4, 5, 2, 1})<<endl;
    cout<<MaxSumBitonicSubSequence({12, 11, 40, 5, 3, 1})<<endl;
    cout<<MaxSumBitonicSubSequence({80, 60, 30, 40, 20, 10})<<endl;
    return 0;
}