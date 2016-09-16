//
// Created by lijiahao on 9/16/16.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
 * 　为将X上的n只盘子借助Y转移至Z，只需（递归地）
 *      将X上的n - 1只盘子借助Z转运至Y
 *      再将X上最后一只盘子直接转移至Z
 *      最后再将Y上的n-1只盘子借助X转运至Z
 */

long long cnt = 0;

void hanoi(string from, string by, string to, int n) {
    if(n-1 > 0) hanoi(from, to, by, n-1);
    cout << from << "->" << to << endl; ++cnt;
    if(n-1 > 0) hanoi(by, from, to, n-1);
}

void hanoi_dp(string from, string by, string to, int n) {
    /*
     * 21:abc 11:bac 01:cab
     * 20:acb 10:bca 00:cba
     */
    string v[3][2][n];
    v[0][0][0] = to + "->" + from + "\n";
    v[0][1][0] = to + "->" + by + "\n";
    v[1][0][0] = by + "->"+ from + "\n";
    v[1][1][0] = by + "->" + to + "\n";
    v[2][0][0] = from + "->" + by + "\n";
    v[2][1][0] = from + "->" + to + "\n";
    for(int k = 1; k < n; ++k) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 2; ++j) {
                v[i][j][k] += v[i][!j][k - 1];
                v[i][j][k] += v[i][j][0];
            }
        v[0][0][k] += v[1][0][k-1];
        v[0][1][k] += v[2][0][k-1];
        v[1][0][k] += v[0][0][k-1];
        v[1][1][k] += v[2][1][k-1];
        v[2][0][k] += v[0][1][k-1];
        v[2][1][k] += v[1][1][k-1];
    }
    cout << v[2][1][n-1] << endl;
    cout << "count:" << count(v[2][1][n-1].begin(), v[2][1][n-1].end(), '>') << endl;
}

int main() {
    //cnt = 0;
    hanoi_dp("a", "b", "c", 6);
    //cout << "count:" << cnt << endl;
    return 0;
}