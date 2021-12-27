#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int countSubsetSumProblem(vector<int> arr, int sum) {
    int n = arr.size();
    vector<vector<int>>t(n+1, vector<int>(sum+1,0));
    for(int i=0;i<=n;i++) {
        t[i][0] = 1;
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    /*
    for (auto oneD : t) {
        cout<<endl;
        for (auto val : oneD) {
            cout<<val<<" ";
        }
    }
    cout<<endl;
    */
    return t[n][sum];
}

int main() {
    vector<int> arr {2,3,5,6,8,10};
    int sum = 10;
    cout<<countSubsetSumProblem(arr, sum)<<endl;
}
