/*
Given a stack with push(), pop(), empty() operations, delete middle of it without using any additional data structure.
Input  : Stack[] = [1, 2, 3, 4, 5]
Output : Stack[] = [1, 2, 4, 5]

Input  : Stack[] = [1, 2, 3, 4, 5, 6]
Output : Stack[] = [1, 2, 4, 5, 6]
*/
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

class Solution {
private:
    stack<int> s;
    void helper(int mid) {
        if(s.size() == mid) {
            s.pop();
            return;
        }

        int temp = s.top();
        s.pop();
        helper(mid);
        s.push(temp);
    }

public:
    Solution (stack<int> data) {
        s = data;
    }

    void deleteMid() {
        int sizeOfStack = s.size();
        int mid = ceil(sizeOfStack/2.0);
        helper(mid);
    }

    void printStack() {
        while(!s.empty()) {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
};

int main() {
    Solution s (stack<int>({1,2}));
    s.deleteMid();
    s.printStack();

    Solution s1 (stack<int>({3,2,1}));
    s1.deleteMid();
    s1.printStack();
}