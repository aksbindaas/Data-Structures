
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int CountSubsetSum(vector<int> nums, int sum) {
        int n = nums.size();
        vector<vector<int>>t(2, vector<int>(sum+1));
        int numsOfZero = 0;
        for (int i=0;i<=n;i++) {
            if(i < n && nums[i] == 0) {
                    numsOfZero++;
            }
            t[i%2][0] = 1;
        }
        for (int i=1;i<=n;i++) {
            for (int j=1; j<=sum;j++) {
                t[i%2][j] = t[(i-1)%2][j];
                if(nums[i-1]<=j && nums[i-1] != 0) {
                    t[i%2][j] += t[(i-1)%2][j-nums[i-1]];
                }
            }
        }
        return pow(2, numsOfZero) * t[n%2][sum];
}

int findTargetSumWays(vector<int> nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (target > sum || (sum + target) % 2 == 1 ) return 0;
    int s1 = (sum+target)/2;
    return CountSubsetSum(nums, abs(s1));
}

#define TARGET 10000
int countTarget(vector<int> A,int pos, int sum, int target, vector<vector<int>>&t) {
    if(pos == A.size()) {
        t[pos][sum+TARGET] = (sum == target) ? 1:0;
        return t[pos][sum+TARGET];
    }
    if(t[pos][sum+TARGET] != 0) {
        return t[pos][sum+TARGET];
    }
    t[pos][sum+TARGET] = countTarget(A, pos+1, sum + -A[pos], target,t)+
                        countTarget(A, pos+1, sum+ A[pos], target,t);
    return t[pos][sum+TARGET];
}
// Using Recursion
int findTargetSumWaysUsingRecursion(vector<int> nums, int target) {
    vector<vector<int>>t(40, vector<int>(2*TARGET+1));
    return countTarget(nums, 0, 0, target, t);
}

int main() {
    cout<<findTargetSumWays({1}, 2)<<endl;
    cout<<findTargetSumWays({100}, -200)<<endl;
    cout<<findTargetSumWays({1,0}, 1)<<endl;
    cout<<findTargetSumWays({1,1,1,1,1}, 3)<<endl;
    cout<<findTargetSumWays({0,0,0,0,0,0,0,0,1}, 1)<<endl;
    cout<<findTargetSumWays({9,7,0,3,9,8,6,5,7,6}, 2)<<endl;
    cout<<findTargetSumWays({2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53}, 1000)<<endl;
    cout<<findTargetSumWays({237 ,339, 308, 309, 368, 204, 64, 417, 433, 135, 485, 113, 364}, 154)<<endl;
    cout<<"--------------------------------------------------\n";
    cout<<findTargetSumWaysUsingRecursion({1}, 2)<<endl;
    cout<<findTargetSumWaysUsingRecursion({100}, -200)<<endl;
    cout<<findTargetSumWaysUsingRecursion({1,0}, 1)<<endl;
    cout<<findTargetSumWaysUsingRecursion({1,1,1,1,1}, 3)<<endl;
    cout<<findTargetSumWaysUsingRecursion({0,0,0,0,0,0,0,0,1}, 1)<<endl;
    cout<<findTargetSumWaysUsingRecursion({9,7,0,3,9,8,6,5,7,6}, 2)<<endl;
    cout<<findTargetSumWaysUsingRecursion({2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53}, 1000)<<endl;
    cout<<findTargetSumWaysUsingRecursion({237 ,339, 308, 309, 368, 204, 64, 417, 433, 135, 485, 113, 364}, 154)<<endl;
}