#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lcsNonRecursion(int m, int n, string s1, string s2) {
    vector<vector<int>>t(m+1, vector<int>(n+1));
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n;j++) {
            if (s1[i-1] == s2[j-1]) {
                t[i][j] = 1+t[i-1][j-1];
            } else {
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t[m][n];
}

int lcsRecursion(int m, int n, string s1, string s2, vector<vector<int>>&t) {
    if(m ==0 || n == 0) {
        return 0;
    }
    if(t[m][n] !=-1) {
        return t[m][n];
    }
    if(s1[m-1] == s2[n-1]) {
        t[m][n] = 1+lcsRecursion(m-1, n-1, s1, s2, t);
        return t[m][n];
    } else {
        t[m][n] = max(lcsRecursion(m-1, n, s1, s2, t), lcsRecursion(m, n-1, s1, s2, t));
        return t[m][n];
    }
}

int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    vector<vector<int>>t(1001, vector<int>(1001, -1));
    cout<<lcsNonRecursion(str1.length(), str2.length(),str1, str2)<<" "<<lcsRecursion(str1.length(), str2.length(),str1, str2, t)<<endl;;
    str1 = "ABCDGH";
    str2 = "AEDFHR";
    for (auto &i : t)
    std::fill(i.begin(), i.end(), -1);
    cout<<lcsNonRecursion(str1.length(), str2.length(),str1, str2)<<" "<<lcsRecursion(str1.length(), str2.length(),str1, str2, t)<<endl;;
    str1 = "ABC";
    str2 = "AC";
    for (auto &i : t)
    std::fill(i.begin(), i.end(), -1);
    cout<<lcsNonRecursion(str1.length(), str2.length(),str1, str2)<<" "<<lcsRecursion(str1.length(), str2.length(),str1, str2, t)<<endl;;
    
    return 0;

}