/*
Matrix Chain Multiplication
Given a sequence of matrices, 
find the most efficient way to multiply these matrices together. 
The efficient way is the one that involves the least number of multiplications.
The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) 
where the ith matrix has the dimensions (arr[i-1] x arr[i]).
*/
#include <iostream>
#include <vector>
using namespace std;

int dp[101][101];

int solveMCM(vector<int> arr, int i , int j) {
    if(i>=j) {
        return 0;
    } 
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int mn = INT_MAX;
    for (int k=i; k<j; k++) {
        int temp = solveMCM(arr, i, k) + solveMCM(arr, k+1, j) + arr[i-1]*arr[k] * arr[j];
        mn = min(mn, temp);
    }
    return dp[i][j] = mn;
}

void printDP(int size) {
    for (int i = 0; i<size;i++) {
        for (int j = 0; j<size;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    memset(dp, -1, sizeof dp);
    int size = 3;
    cout<<solveMCM({40,20,30}, 1, size -1)<<endl;
    printDP(size);
    
    size = 4;
    memset(dp, -1, sizeof dp);
    cout<<solveMCM({40,20,30,10}, 1, size -1)<<endl;
    printDP(size);

    size = 5;
    memset(dp, -1, sizeof dp);
    cout<<solveMCM({40,20,30,10,30}, 1, size -1)<<endl;
    printDP(size);
}