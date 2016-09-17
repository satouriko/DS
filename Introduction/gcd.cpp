//
// Created by lijiahao on 9/17/16.
//

#include <iostream>
using namespace std;

#define abs(x) ((x) > 0 ? (x) : -(x))

//欧几里得算法（辗转相除法）
int gcd_eu(int a, int b) {
    cout << a << ' ' << b << endl;
    if(b == 0)
        return a;
    else if(a == 0)
        return b;
    else return a > b ? gcd_eu(b, a % b) : gcd_eu(a, b % a);
}

//中华更相减损法
int gcd_cn(int a, int b) {
    int p = 1;
    while(a & 1 == 0 && b & 1 == 0)
    {
        p <<= 1;
        a >>= 1;
        b >>= 1;
    }
    int t;
    while(1) {
        t = abs(a - b);
        cout << t << ' ' << a << ' ' << b << endl;
        if(t == 0)
            return a * p;
        while(t & 1 == 0)
             t >>= 1;
        a >= b ? a = t : b = t;
    }
}

int main() {
    cout << gcd_eu(2016,2645) << endl;
    cout << gcd_cn(2016,2645) << endl;
}