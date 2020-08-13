//
// Created by lsqy on 2020/8/13.
//

/* 1094 谷歌的招聘 (20分)
 * 耗时：13:36.43
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num) {
    if (num == 0) return true;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(void) {
    int l, k;
    string str;

    cin >> l >> k >> str;

    for (int i = 0; i + k <= str.size(); ++i) {
        if (is_prime(stoi(str.substr(i, k)))) {
            cout << str.substr(i, k) << endl;
            return 0;
        }
    }

    cout << "404" << endl;
    return 0;
}
