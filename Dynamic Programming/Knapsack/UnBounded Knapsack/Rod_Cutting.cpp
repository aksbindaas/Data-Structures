/*
Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
For example, if the length of the rod is 8 and the values of different pieces are given as the following, 
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable value is 24 (by cutting in eight pieces of length 1) 

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.

*/

#include<iostream>
#include<vector>
#include <numeric>
using namespace std;

int unBoundedKnapsack(vector<int> price) {
    int n = price.size();
    vector<vector<int>>t(n+1, vector<int>(n+1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if(i<=j) {
                t[i][j] = max(t[i-1][j], price[i-1]+t[i][j-i]);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][n];
}

int unBoundedKnapsack(vector<int> price, vector<int> weight, int max_len , int n) {
    if (n == 0) {
        return 0;
    }
    if(weight[n-1] > max_len) {
        return unBoundedKnapsack(price, weight,max_len, n-1);
    } else {
        return max(unBoundedKnapsack(price, weight,max_len, n-1), 
        price[n-1] + unBoundedKnapsack(price, weight, max_len - weight[n-1],n));
    }
}

int main () {
    vector<int> val {1, 5, 8, 9, 10, 17, 17, 20};
    cout<<unBoundedKnapsack(val)<<endl;

    std::vector<int> weight(val.size());
    iota(weight.begin(), weight.end(), 1);
    cout<<unBoundedKnapsack(val, weight,val.size(), val.size())<<endl;
}