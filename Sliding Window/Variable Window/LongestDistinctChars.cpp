/*
Given a string S, find length of the longest substring with all distinct characters. 

Example 1:

Input:
S = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest 
substring with all distinct characters.
*/


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void solve(string s) {
    int n = s.length();
    int i = 0, j = 0;
    int ws = INT_MIN;
    unordered_map<char, int> mp;
    int currentWindowSize = 0;
    while (j < n) {
        mp[s[j]]++;
        currentWindowSize = j-i+1;
        if(mp.size() <= currentWindowSize) {
            if(mp.size() == currentWindowSize) {
                ws = max(ws, currentWindowSize);
            } else {
                while (mp.size() < j-i+1 ) {
                    if(--mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
    }
    cout<<"Longest Window Size "<<ws<<endl;
}

int main() {
    solve("geeksforgeeks");
    solve("aaa");
    solve("aldshflasghdfasgfkhgasdfasdgvfyweofyewyrtyefgv");
    return 0;
}