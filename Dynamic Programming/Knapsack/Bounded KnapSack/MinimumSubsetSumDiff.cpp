/*
Given a set of integers, the task is to divide it into two sets S1 and S2 
such that the absolute difference between their sums is minimum. 
If there is a set S with n elements, then if we assume Subset1 has m elements, 
Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.
*/


#include <iostream>
#include<vector>
#include <numeric>
using namespace std;

vector<int> isSubsetSum(const vector<int>&arr, int sum, int n) {
    vector<vector<int>> cachedDP(n+1,vector<int>(sum+1, 0));
    for (int i=0; i<=n ; i++) {
        cachedDP[i][0] = true;
    }

    for(int i = 1; i<=n; i++) {
        for (int j = 1; j<=sum; j++) {
            if(arr[i-1]<=j) {
                cachedDP[i][j] = cachedDP[i-1][j] + cachedDP[i-1][j-arr[i-1]];
            } else {
                cachedDP[i][j] = cachedDP[i-1][j];
            }
        }
    }
    for (auto oneD : cachedDP) {
        cout<<endl;
        for (auto val : oneD) {
            cout<<val<<" ";
        }
    }
    cout<<endl;
    return cachedDP[n];
}


int minSubsetSumDiff(const vector<int> &arr) {
    int sum = accumulate(arr.begin(), arr.end(),0);
    int n = arr.size();
    int halfPartitionForS1 = sum/2;

    cout<<"S1 Range: "<<halfPartitionForS1<<" "<<sum<<endl;
    auto cachedDP = isSubsetSum(arr, halfPartitionForS1, n);
    
    int minSum = INT_MAX;
    for (int i=0; i<=halfPartitionForS1; i++) {
        if(cachedDP[i] != 0) {
            cout<<"Subset Sum is Available for sum: "<<i<<endl;
            minSum = min(sum - 2*i, minSum);
        }
    }
    return minSum;
}

int main() {
    vector<int> arr {1,6,11,5};
    cout<<minSubsetSumDiff(arr)<<endl;

    vector<int> arr1 {1,2,7};
    cout<<minSubsetSumDiff(arr1)<<endl;
    
    vector<int> arr2 {20,19,18,20,16};
    cout<<minSubsetSumDiff(arr2)<<endl;
}