/*
The following is a description of the instance of this famous puzzle involving n=2 eggs and a building with k=36 floors.
Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the eggs to break on landing. We make a few assumptions:
…..An egg that survives a fall can be used again. 
…..A broken egg must be discarded. 
…..The effect of a fall is the same for all eggs. 
…..If an egg breaks when dropped, then it would break if dropped from a higher floor. 
…..If an egg survives a fall then it would survive a shorter fall. 
…..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.
If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out in only one way. Drop the egg from the first-floor window; if it survives, drop it from the second-floor window. Continue upward until it breaks. In the worst case, this method may require 36 droppings. Suppose 2 eggs are available. What is the least number of egg-droppings that is guaranteed to work in all cases? 
The problem is not actually to find the critical floor, but merely to decide floors from which eggs should be dropped so that the total number of trials are minimized.
*/
#include <iostream>
using namespace std;

int dp[201][201];
int solve(int e, int f) {
    if(e == 1 || f<=1) {
        return f;
    }
    if(dp[e][f] != -1) {
        return dp[e][f];
    }
    int ans = INT_MAX;
    for (int k = 1; k<=f; k++) {
        int c1, c2; 
        // if egg is broken 
        if(dp[e-1][k-1] != -1) {
            c1 = dp[e-1][k-1];
        } else {
            c1 = solve(e-1, k-1);
            dp[e-1][k-1] = c1;
        }
        // if egg is not broken 
        if(dp[e][f-k] != -1) {
            c2 = dp[e][f-k];
        } else {
            c2 = solve(e, f-k);
            dp[e][f-k] = c2;
        }
        int temp = 1+max(c1, c2);
        ans = min(ans, temp);
    }
    return dp[e][f] = ans;
}

int main() {
    memset(dp , -1, sizeof dp);
    cout<<solve(0, 10)<<endl;

    memset(dp , -1, sizeof dp);
    cout<<solve(1, 50)<<endl;
    
    memset(dp , -1, sizeof dp);
    cout<<solve(100, 1)<<endl;
    
    memset(dp , -1, sizeof dp);
    cout<<solve(2, 10)<<endl;
    return 0;
}