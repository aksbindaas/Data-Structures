/*
Given two strings s and t, return the minimum window in s which will contain all the characters in t. 
If there is no such window in s that covers all characters in t, return the empty string "".
Note that If there is such a window, 
it is guaranteed that there will always be only one unique minimum window in s.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:

Input: s = "a", t = "a"
Output: "a"

Input: string = “this is a test string”, pattern = “tist” 
Output: Minimum window is “t stri” 
Explanation: “t stri” contains all the characters of pattern.

Input: string = “geeksforgeeks”, pattern = “ork” 
Output: Minimum window is “ksfor”

S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void solve(string s, string p) {
    int i = 0, j = 0, n = s.length();
    unordered_map<char, int> mp;
    for (auto c : p) {
        mp[c]++;
    }
    int start = 0; // starting index of ans
    int count  = mp.size();
    int ws = INT_MAX;
    while (j < n) {
        if(--mp[s[j]] == 0) {
            count--;
        }
        if(count == 0) {
            while (count == 0) {
                if(ws > j-i+1) {
                    ws = j-i+1;
                    start = i;
                }
                if(++mp[s[i]] > 0) {
                    count++;
                }
                i++;
            }
        }
        j++;
    }
    if(ws != INT_MAX) {
        cout<<s.substr(start, ws)<<endl;
    }
}

int main() {
    solve("timetopractice", "toc");
    solve("geeksforgeeks", "ork");
    solve("this is a test string", "tist");
    return 0;
}