#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Write a function 'fib(n)' that takes in a number as an argument.
 * The function should return the n-th number of Fibonacci sequence.
 *
 * The 1st and 2nd number of the sequence is 1.
 * To generate the next of the sequence, we sum the previous two.
 *
 * n : 1, 2, 3, 4, 5, 6, 7,  8,  9,  ...
 * fib(n): 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
 */

int64_t fib(int64_t n){
    int64_t f[2]{0,1};
    if(n<2) return f[n];
    for(int64_t i{2}; i<n+1; i++){
        swap(f[0], f[1]);
        f[1] += f[0];
    }
    return f[1];
}

int main()
{
    int64_t v[6]{2,3,6,7,8,50};
    for_each(v, v+6, [&](auto& n){cout << fib(n) << " ";});
    cout << endl;
    return 0;
}
