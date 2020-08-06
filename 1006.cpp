//
// Created by lsqy on 2020/8/6.
//

/* 1006 换个格式输出整数 (15分)
 * 耗时：4:19.39
 */
#include <iostream>

using namespace std;

int main(void) {
    int num;
    cin >> num;
    for (int i = 0; i < num / 100; ++i) {
        cout << "B";
    }
    for (int j = 0; j < (num % 100) / 10; ++j) {
        cout << "S";
    }
    for (int k = 0; k < num % 10; ++k) {
        cout << k+1;
    }
    cout << endl;
    return 0;
}