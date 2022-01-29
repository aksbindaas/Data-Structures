/*
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules: 

Only one disk can be moved at a time.
Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
No disk may be placed on top of a smaller disk.
*/

#include <iostream>
using namespace std;

void solve(int n , string source, string dest, string helper) {
    if(n == 1) {
        cout<<"Moving Disk "<<n<<" from "<<source<<" dest "<<dest<<endl;
        return;
    }
    solve(n-1, source, helper, dest);
         cout<<"Moving Disk "<<n<<" from "<<source<<" dest "<<dest<<endl;
    solve(n-1, helper, dest, source);
}

int main() {
    solve(65, "A", "C", "B");
    return 0;
}