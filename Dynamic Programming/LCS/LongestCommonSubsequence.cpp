#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> mem;

string key(int i, int j) {
    return to_string(i)+","+to_string(j);
}

int lcs(const string str, int i, const int m,  const string str1, int j, const int n) {
    if (mem[key(i, j)] != 0)
        return mem[key(i, j)];
    else if(i == m || j == n) {
        mem[key(i, j)] = 0;
    }
    else if(str[i] == str1[j]) {
        mem[key(i, j)] = 1 + lcs(str, i+1, m, str1, j+1, n);
    } 
    else {
        mem[key(i, j)] = max(lcs(str,i+1, m, str1, j, n), lcs(str, i, m , str1, j+1, n));
    }
    return mem[key(i, j)];
}



int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    cout<<lcs(str1, 0, str1.length(), str2, 0, str2.length())<<endl;
    return 0;
}