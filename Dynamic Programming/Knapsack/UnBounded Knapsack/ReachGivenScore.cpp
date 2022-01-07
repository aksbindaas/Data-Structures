/*
Reach a given score
Consider a game where a player can score 3 or 5 or 10 points in a move. 
Given a total score n, find number of distinct combinations to reach the given score.
*/
#include <iostream>
using namespace std;

void util(long long int t[], int k, long long int n) {
    for (long long int i = k; i <= n; i++) {
        t[i] += t[i-k];
    }
}

long long int solve(int n) {
    long long int t[n+1];
    memset(t, 0, sizeof t);
    t[0] = 1;
    util(t, 3, n);
    util(t, 5, n);
    util(t, 10, n);
    return t[n];
}

int main() {
    for (int i= 1; i<= 20; i++)
        cout<<solve(i)<<endl;
    return 0;
}