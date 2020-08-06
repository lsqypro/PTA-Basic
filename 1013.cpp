//
// Created by lsqy on 2020/8/6.
//

/* 1013 数素数 (20分)
 * 耗时：14:54.69
 *
 */
#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int num) {
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(void) {
    int m, n, cnt = 0;

    cin >> m >> n;

    for (int i = 2; true; ++i) {
        if (isprime(i))  {
            cnt++;
            if (cnt >= m && cnt <= n) {
                cout << i;
                if ((cnt-m+1) % 10 == 0 || cnt == n) cout << endl;
                else cout << " ";
            }
            if (cnt == n) {
                break;
            }
        }
    }
    return 0;
}