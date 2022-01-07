#include <iostream>
#include <numeric>   
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>arr, int sum, int n) {
    if (sum == 0) return true;
    if (n == 0)   return false;
    if(arr[n-1] > sum) {
        return isSubsetSum(arr, sum , n-1);
    } else {
        return isSubsetSum(arr, sum , n-1) || isSubsetSum(arr, sum- arr[n-1], n-1);
    }
}

bool isSubsetSum(vector<int>arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> t(n+1, vector<bool>(sum+1));
    // initialise vector
    for (int i=0; i<=sum; i++) {
        t[0][i] = false; 
    }
    for (int i=0; i<=n; i++) {
        t[i][0] = true; 
    }

    // create DP table
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    /*
    for (vector<bool> oneD : t) {
        cout<<endl;
        for (bool val : oneD) {
            cout<< ((val==true)? 'T':'F')<<" ";
        }
    }
    cout<<endl;
    */
    return t[n][sum];
}

bool isEqualSumPartition(vector<int>arr, bool isRecursive = false) {
    int sum = accumulate(arr.begin(),arr.end(), 0);
    // if total is even then only we are divide into two subpart.
    if(sum%2 != 0) {
        return false;
    } else {
        if(isRecursive == false)
            return isSubsetSum(arr,sum/2);
        else {
            return isSubsetSum(arr,sum/2, arr.size());
        }
    }
}



int main() {
    vector<int>arr {1,5,11,5};
    cout<<isEqualSumPartition(arr, false)<<endl;

    cout<<isEqualSumPartition(arr, true)<<endl;
}