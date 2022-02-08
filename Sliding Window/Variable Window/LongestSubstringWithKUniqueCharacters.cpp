/*
Given a string you need to print longest possible substring that has exactly M unique characters. If there are more than one substring of longest possible length, then print any one of them.

Examples: 

"aabbcc", k = 1
Max substring can be any one from {"aa" , "bb" , "cc"}.

"aabbcc", k = 2
Max substring can be any one from {"aabb" , "bbcc"}.

"aabbcc", k = 3
There are substrings with exactly 3 unique characters
{"aabbcc" , "abbcc" , "aabbc" , "abbc" }
Max is "aabbcc" with length 6.

"aaabbb", k = 3
There are only two unique characters, thus show error message. 
Source: Google Interview Question.
*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(string s, int k) {
    int n = s.length();
    int i = 0, j = 0;
    int ws = INT_MIN;
    unordered_map<char, int> mp;
    while (j < n) {
        mp[s[j]]++;
        if(mp.size() <= k) {
            if(mp.size() == k) {
                ws = max(ws, j-i+1);
            }
        }
        else  {
            while (mp.size() > k) {
                if(--mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    if(ws == INT_MIN) {
        ws = -1;
    }
    cout<<"Largest Window Size "<<ws<<endl;
}

int main() {
    solve("aabacbebebe", 3);
    solve("aaaa", 2);
    solve("hq", 2);
    solve("ffmznim", 4);
    return 0;
}