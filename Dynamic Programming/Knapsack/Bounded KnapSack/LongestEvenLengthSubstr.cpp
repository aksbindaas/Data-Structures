/*
Longest Even Length Substring
For given string ‘str’ of digits, find length of the longest substring of ‘str’, such that the length of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits.
 

Input:

The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains a string string of length N.

Output:

Print length of the longest substring of length 2k such that sum of left k elements is equal to right k elements and if there is no such substring print 0.
*/
#include<iostream>
#include <vector>
#include <numeric>
using namespace std;

int solve(string str) {
    int n = str.length();
    int ans = 0;
    for (int i=0; i<= n-2; i++) {
        int lsum = 0, rsum = 0;
        int l = i, r = i+1;
        while (r<n && i>=0) {
            lsum += str[l] - '0';
            rsum += str[r] - '0';
            if(lsum == rsum) {
              ans = max(ans, r-l+1);
            }
            l--;
            r++;
        }
    }
    return ans;
}
    
int main() {
    cout<<solve("000000")<<endl;
    cout<<solve("1234123")<<endl;
	return 0;
}