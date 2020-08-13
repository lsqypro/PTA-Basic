//
// Created by lsqy on 2020/8/13.
//

/* 1087 有多少不同的值 (20分)
 * 耗时：05:02.56
 *
 */

#include <iostream>

using namespace std;

int cnt_map[100000] = {0};  // 10000/2+10000/3+10000/5 = 10333.333

int main(void) {
//    算式 ⌊n/2⌋+⌊n/3⌋+⌊n/5⌋ 有多少个不同的值
    int n, tmp, cnt = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        tmp = i/2 + i/3 + i/5;
        if (cnt_map[tmp]++ == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
