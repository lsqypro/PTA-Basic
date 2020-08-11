//
// Created by lsqy on 2020/8/11.
//

/* 1056 组合数的和 (15分)
 * 耗时：5:14.32
 *
 * 1. 以i为十位，n-1种可能
 * 2. 以i为个位，n-1种可能
 */

#include <iostream>

using namespace std;

int main(void) {
    int n, sum = 0, value;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        sum += (n-1) * value * 10 + (n-1) * value;
    }
    cout << sum << endl;

    return 0;
}