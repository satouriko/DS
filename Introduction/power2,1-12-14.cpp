//
// Created by lijiahao on 9/16/16.
//

#include <iostream>
using namespace std;

#define sqr(x) (x * x)

//递归版O(n)
long long power2BF_I(int n) {
    if(n == 0)
        return 1;
    else
        return power2BF_I(--n) << 1;
}

//迭代版O(logn)
long long power2(int n) {
    int result = 1;
    while(n >>= 1) {

    }
}

int main() {
    cout << power2BF_I(10) << endl;
    cout << power2(10) << endl;
}