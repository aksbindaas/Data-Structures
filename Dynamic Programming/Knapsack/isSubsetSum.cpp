#include<iostream>
#include<vector>
using namespace std;
// Only Recursive
int isSubsetSum(int arr[], int sum, int n) {
    if (sum == 0) {
        return true;
    }
    if(n == 0) {
        return false;
    }
    if(arr[n-1] > sum) {
        return isSubsetSum(arr, sum, n-1);
    } else {
        return isSubsetSum(arr, sum, n-1) || isSubsetSum(arr, sum - arr[n-1], n-1);
    }
}

// Recursive Memotization
bool isSubsetSum(int arr[], int sum, int n , vector< vector<int> > &t) {
    if(sum == 0) {
        t[n][sum] = 1;
    } else if(n==0) {
        t[n][sum] = 0;
    } else if(t[n][sum] != -1) {
        return t[n][sum];
    } else if(arr[n-1] <= sum) {
        t[n][sum] = isSubsetSum(arr, sum, n-1, t) || isSubsetSum(arr, sum-arr[n-1], n-1, t);
    } else if(arr[n-1] > sum) {
        t[n][sum] = isSubsetSum(arr, sum, n-1, t);
    }
    return t[n][sum];
}

// botton up approach

bool isSubSetSumNonRecursive(int arr[], int sum , int n) {
    vector<vector<bool>>subset(n+1, vector<bool>(sum+1));
    // Initialisation 
    for (int i=0; i<= sum ; i++) {
        subset[0][i] = false;
    }
    for (int i=0; i<= n ; i++) {
        subset[i][0] = true;
    }

    for (int i=1 ; i<=n ; i++) {
        for (int j=1; j<=sum; j++) {
            if(arr[i-1] <= j) {
                subset[i][j] = subset[i-1][j] || subset[i-1][j - arr[i-1]];
            }
            else {
                subset[i][j] = subset[i - 1][j];
            }
        }
    }
    /*
    for (vector<bool> oneD : subset) {
        cout<<endl;
        for (bool val : oneD) {
            cout<< ((val==true)? 'T':'F')<<" ";
        }
    }
    cout<<endl;
    */
    return subset[n][sum];
}

int main() {
    int a[] = {3,4,5,2};
    int n = sizeof(a)/sizeof(int);
    int sum = 6;
    std::cout<<isSubsetSum(a, sum, n)<<endl;

    vector<vector<int> >t(n+1,vector<int>(sum+1, -1));
    std::cout<<isSubsetSum(a, sum, n, t)<<endl;
    std::cout<<isSubSetSumNonRecursive(a, sum, n)<<endl;


}