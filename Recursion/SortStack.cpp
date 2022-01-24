/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.
*/

#include <iostream>
#include <stack>
using namespace std;

class Solve {
private:
    stack<int> s;
    void insert(int val) {
        if(s.size() == 0 || s.top() < val) {
            s.push(val);
            return;
        }
        int temp = s.top();
        s.pop();
        insert(val);
        s.push(temp);
    }
public:
    Solve(stack<int> data) {
        s = data;
    }

    void sort() {
        if(s.size() == 1) {
            return;
        }
        int temp = s.top();
        s.pop();
        sort();
        insert(temp);
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
    Solve s (stack<int>({1,2,3}));
    s.sort();
    s.printStack();

    Solve s1 (stack<int>({3,2,1}));
    s1.sort();
    s1.printStack();
}