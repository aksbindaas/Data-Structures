/*
Reach a given score
Consider a game where a player can score 3 or 5 or 10 points in a move. 
Given a total score n, find number of distinct combinations to reach the given score.
*/
#include <iostream>
using namespace std;

int solve(int n) {
    int t[n+1];
    memset(t, 0, sizeof t);
    t[0] = 1;
    for (int i = 3; i<=n; i++) {
        t[i] += t[i-3];
    }
    for (int i = 5; i<=n; i++) {
        t[i] += t[i-5];
    }
    for (int i = 10; i<=n; i++) {
        t[i] += t[i-10];
    }

    return t[n];
}

int main() {
    for (int i= 1; i<= 20; i++)
        cout<<solve(i)<<endl;
    return 0;
}