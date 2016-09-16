//
// Created by lijiahao on 9/16/16.
//

#include <iostream>
using namespace std;

/*
 * 　为将X上的n只盘子借助Y转移至Z，只需（递归地）
 *      将X上的n - 1只盘子借助Z转运至Y
 *      再将X上最后一只盘子直接转移至Z
 *      最后再将Y上的n-1只盘子借助X转运至Z
 */

long long cnt = 0;

void hanoi(char from, char by, char to, int n) {
    if(n-1 > 0) hanoi(from, to, by, n-1);
    cout << from << "->" << to << endl; ++cnt;
    if(n-1 > 0) hanoi(by, from, to, n-1);
}

int main() {
    cnt = 0;
    hanoi('a', 'b', 'c', 6);
    cout << "count:" << cnt << endl;
    return 0;
}