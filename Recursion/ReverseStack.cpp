/*
Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S: 
isEmpty(S) 
push(S) 
pop(S)
*/
#include <iostream>
#include <stack>
using namespace std;
class Solve {
private:
stack<int>s;
    void helper(int val) {
        if(s.size() == 0) {
            s.push(val);
            return;
        }
        int temp = s.top();
        s.pop();
        helper(val);
        s.push(temp);
    }
public:
    Solve(stack<int> data) {
        s = data;
    }
    void reverse() {
        if(s.size() == 1) {
            return;
        }
        int temp = s.top();
        s.pop();
        reverse();
        helper(temp);
    }

    void print() {
        auto s = this->s;
        while(!s.empty()) {
            cout<<s.top()<<" ";s.pop();
        }
        cout<<endl;
    }
};


int main() {
    Solve s(stack<int>({1,2,3,4,5,6,7}));
    s.print();
    s.reverse();
    s.print();
    return 0;
}