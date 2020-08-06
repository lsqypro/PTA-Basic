//
// Created by lsqy on 2020/8/6.
//

/* 1007 素数对猜想 (20分)
 * 耗时：11:36.97
 */
#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num) {
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(void) {
    int n, sum = 0;
    int pre = 1;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        if (is_prime(i)) {
            if (i - pre == 2) sum++;
            pre = i;
        }
    }
    cout << sum;
    return 0;
}