//
// Created by lsqy on 2020/8/6.
//

/* 1012 数字分类 (20分)
 * 耗时：24:32.81
 *
 */
#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
    int n, num, opt = 1, sum2 = 0, max = 0;
    double sum4 = 0;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num % 5 == 0 && num % 2 == 0) a1 += num; // 有即一定大于0
        else if (num % 5 == 1) {  // 之和可能为0
            sum2 += opt * num, opt *= -1;
            a2++;
        }
        else if (num % 5 == 2) a3++;  // 有即一定大于0
        else if (num % 5 == 3) {   // 求平均
            sum4 += num;
            a4++;
        }
        else if (num % 5 == 4) {
            a5++;
            if (max < num) max = num;
        }
    }
    if (a1) cout << a1 << " ";
    else cout << "N ";
    if (a2) cout << sum2 << " ";
    else cout << "N ";
    if (a3) cout << a3 << " ";
    else cout << "N ";
    if (a4) printf("%0.1f ", sum4/a4);
    else cout << "N ";
    if (a5) cout << max;
    else cout << "N";
    cout << endl;
    return 0;
}