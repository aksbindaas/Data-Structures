/*
Given a word and a text, return the count of the occurrences of anagrams of the word in the text
(For eg: anagrams of word for are for, ofr, rof etc.))
Examples: 

Input : forxxorfxdofr
        for
Output : 3
Explanation : Anagrams of the word for - for, orf, 
ofr appear in the text and hence the count is 3.

Input : aabaabaa
        aaba
Output : 4
Explanation : Anagrams of the word aaba - aaba, 
abaa each appear twice in the text and hence the
count is 4.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void solve(string txt, string pat) {
    int n = txt.length();
    
    int i =0 , j = 0;
    unordered_map<char, int> pat_mp;
    int k = 0;
    for (auto c : pat) {
        pat_mp[c]++;
        k++;
    }
    unordered_map<char, int> txt_mp;
    int ans = 0;
    while (j < n) {
        txt_mp[txt[j]]++;
        if(j-i+1 <k) {
            j++;
        } else {
            if(txt_mp == pat_mp)  {
                ans++;
            }
        
            if(--txt_mp[txt[i]] == 0) {
                txt_mp.erase(txt[i]);
            }
            i++;
            j++;
        }
    }
    cout<<"Found Anagram "<<ans<<endl;
}

int main() {
    solve("forxxorfxdofr", "for");
    solve("aabaabaa", "aaba");
    return 0;
}
