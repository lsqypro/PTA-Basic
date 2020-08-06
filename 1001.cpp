//
// Created by lsqy on 2020/8/5.
//

/* 1001 害死人不偿命的(3n+1)猜想 (15分)
 * 耗时：8:05.37
 */
#include <iostream>

using namespace std;

int main(void) {
    int n, num = 0;
    cin >> n;
    while (n != 1) {
        num++;
        if (n % 2 == 0) n = n / 2;
        else n = (3 * n + 1) / 2;
    }
    cout << num;
    return 0;
}