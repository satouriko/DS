//
// Created by lijiahao on 9/16/16.
//

#include <iostream>
using namespace std;

#define sqr(x) multiply(x,x)
#define fib(x) power(x)[1]

long long* multiply(long long *input1, long long *input2) {
    long long *result = new long long[4];
    result[0] = *input1 * *input2 + *(input1+1) * *(input2+2);
    result[1] = *input1 * *(input2+1) + *(input1+1) * *(input2+3);
    result[2] = *(input1+2) * *input2 + *(input1+3) * *(input2+2);
    result[3] = *(input1+2) * *(input2+1) + *(input1+3) * *(input2+3);
    return result;
}

long long* power (int n) {
    long long *pow = new long long[4];
    long long *p = new long long[4];
    pow[0] = 1; pow[1] = 0; pow[2] = 0; pow[3] = 1;
    p[0] = 0; p[1] = 1; p[2] = 1; p[3] = 1;
    while (n > 0) {
        if (n & 1) {
            long long *pow_old = pow;
            pow = multiply(pow, p);
            delete pow_old;
        }
        n >>= 1;
        long long *p_old = p;
        p = sqr(p);
        delete p_old;
    }
    return pow;
}

int main() {
    for(int i = 1; i <= 45; ++i)
        cout << i << '\t' << fib(i) << endl;
}