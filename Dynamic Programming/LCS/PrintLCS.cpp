#include<iostream>
#include<string>
#include <set>
#include<map>
#include <tuple>
using namespace std;
int dp[51][51];
int lcs_len;

void printDP(int x, int y) {
    cout<<"********************************\n";
    for (int i = 0; i<= x; i++) {
    for (int j = 0; j<= y; j++) {
        cout<<" "<<dp[i][j]<<"  ";
    }
    cout<<endl;
}
}

int lcs(string s, string t, int x, int y, int i, int j) {
    int &ret = dp[i][j];
    if(i==x || j==y) {
        return  ret = 0;
    }
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    if(s[i] == t[j]) {
        ret = 1+ lcs(s, t, x, y, i+1, j+1); 
    } else {
        ret = max(lcs(s, t, x, y, i+1, j), lcs(s, t, x, y, i, j+1));
    }
    return ret;
}

void printAllLCS(string s, string t, int x, int y, int idx1, int idx2, int curr_lcs, char data[]) {
    if(curr_lcs == lcs_len) {
        data[curr_lcs] = '\0';
        cout<<data<<endl;
        return;
    }
    if(idx1 == x || idx2 == y) return;
    
    for (char ch = 'a'; ch <= 'z'; ch++) {
        bool done = false;
        for (int i = idx1; i<x; i++) {
            if(s[i] == ch) {
                for (int j=idx2; j< y; j++) {
                    if(t[j] == ch) {
                        data[curr_lcs] = ch;
                        printAllLCS(s, t, x, y, i+1, j+1, curr_lcs+1, data);
                        done = true; 
                        break;
                    }
                }
            }
            if(done) {
                break;
            }
        }
    }
}

int main() {
string s1 = "abc", s2 = "bcacb";
int x = s1.length(), y = s2.length();
memset(dp, -1, sizeof(dp));
lcs_len = lcs (s1,s2, x, y, 0, 0);
printDP(x, y);
char data[51];
printAllLCS(s1,s2, x, y, 0, 0, 0, data);
return 0;
}