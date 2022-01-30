/*
There are n people standing in a circle (numbered clockwise 1 to n) waiting to be executed. 
The counting begins at point 1 in the circle and proceeds around the circle in a fixed direction (clockwise). 
In each step, a certain number of people are skipped and the next person is executed. 
The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), 
until only the last person remains, who is given freedom.
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed 
in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
Input:
n = 2, k = 1
Output:
2
Explanation:
Here, n = 2 and k = 1, then safe position is
2 as the person at 1st position will be killed.

Input:
n = 4, k = 2
Output:
1
Explanation:
The safe position is 1.
*/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void solve(vector<int>&army, int sword, int k, int &val) {
    if(army.size() == 1) {
        val = army[0];
        return;
    }
    sword = (sword+k)%army.size();
    army.erase(army.begin()+sword);
    solve(army, sword, k, val);
}

void safeArea(int n, int k) {
    vector<int> army(n);
    iota(army.begin(), army.end(), 1);
    int ans = -1;
    solve(army, 0, k-1, ans);
    cout<<"Safe position "<<ans<<endl;
}

int main() {
    safeArea(40, 7);
    return 0;
}