/*
Boolean Parenthesization
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int dp[201][201][2];

int getDPValue(int i, int j, bool isTrue) {
    return dp[i][j][isTrue];
}



int solve(string s, int i , int j , bool isTrue) {
    if(i> j) {
        return false;
    }
    if(i == j) {
        if(isTrue == true) {
            return (s[i] == 'T');
        }
        if(isTrue == false) {
            return (s[i] == 'F');
        }
    }
    
    if(getDPValue(i, j, isTrue) != -1) {
        return getDPValue(i, j, isTrue);
    }
    int ans = 0;
    int leftT, leftF,rightT, rightF;
    for (int k = i+1; k<j; k+=2) {
        if(getDPValue(i, k-1, true) != -1 ) {
            leftT = getDPValue(i, k-1, true);
        } else {
            leftT = solve(s,i,k-1,true);
        }

        if(getDPValue(i, k-1, false) != -1 ) {
            leftF = getDPValue(i, k-1, false);
        } else {
            leftF = solve(s,i,k-1,false);
        }

        if(getDPValue(k+1, j, true) != -1 ) {
            rightT = getDPValue(k+1, j, true);
        } else {
            rightT = solve(s,k+1,j,true);
        }

        if(getDPValue(k+1, j, false) != -1 ) {
            rightF = getDPValue(k+1, j, false);
        } else {
            rightF = solve(s,k+1,j,false);
        }
        
        if(s[k] == '&') {
            if(isTrue == true) {
                ans+= leftT * rightT;
            } else {
                ans+= leftT * rightF + 
                      leftF * rightT + 
                      leftF * rightF;
            }
        } else if(s[k] == '|'){
            if(isTrue == true) {
                ans += leftT * rightF + 
                       leftF * rightT +  
                       leftT * rightT;
            } else {
                ans += leftF * rightF;
            }
        } else {
            if(isTrue == true) {
                ans += leftT * rightF + 
                       leftF * rightT;
            } else {
                ans += leftF * rightF + 
                       leftT * rightT;
            }
        }
        dp[i][j][isTrue] = ans%1003;
    }
    return ans%1003;
}

int main() {
    string str = "T|T&F^T";
    memset(dp, -1, sizeof dp);
    cout<<solve(str, 0, str.length()-1, true)<<endl;

    str = "T^F|F";
    memset(dp, -1, sizeof dp);
    cout<<solve(str, 0, str.length()-1, true)<<endl;

    str = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
    memset(dp, -1, sizeof dp);
    cout<<solve(str, 0, str.length()-1, true)<<endl;
    return 0;
}