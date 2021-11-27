#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
#define N 6
long long int mem[N] = {0};
mutex mtx;

long long int fib (int n) {
    if(mem[n] != 0) return mem[n];
    if(n == 0) return 0;
    if(n == 1) return 1;
    return mem[n] =  fib(n-1) + fib(n-2);
}

void fib_helper(int n) {
    mtx.lock();
    cout<<"Fibanaci of "<<n<<" is "<<fib(n)<<endl;
    mtx.unlock();
}

int main() {    
    thread ret[N+2];
    for (int i = 1 ; i <= N ; i++) {
        ret[i] = thread(fib_helper, i*10); 
    }
    for (int i = 1 ; i <= N ; i++) {
       ret[i].join();
    }

    return 0;
}