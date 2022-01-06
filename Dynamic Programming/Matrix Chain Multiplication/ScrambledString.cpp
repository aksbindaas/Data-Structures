/*
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, bool> mp;
string key(string a, string b) {
    return a+" "+b;
}
int solve(string a, string b) {
    int n = a.length();
    // if length is not equal then it is not scrambled string
    if(n != b.length()) {
        return false;
    }
    // if length is not equal then it is not scrambled string
    if(a == b) {
        return true;
    }

    if(n <= 1) {
        return false;
    }

    if(mp.find(key(a, b)) != mp.end()) {
        return mp[key(a, b)];
    }
    int flag = false; 

    for (int i =1; i< n ; i++) {
        // condition 1 with swaping
        bool cond1 = solve(a.substr(0, i), b.substr(n-i, i)) && 
                     solve(a.substr(i, n-i), b.substr(0, n-i));
        // condition 1 without swaping
        bool cond2 = solve(a.substr(0, i), b.substr(0, i)) && 
                     solve(a.substr(i, n-i), b.substr(i, n-i));
        if(cond1 || cond2) {
            mp[key(a, b)] = flag = true;
            break;
        }
    }
    return mp[key(a, b)] = flag;
}

int main() {
    cout<<solve("tqxpxeknttgwoppemjkivrulaflayn", "afaylnlurvikjmeppowgttnkexpxqt")<<endl;
    mp.clear();
    cout<<solve("great", "rgeat11111")<<endl;
    return 0;
}

