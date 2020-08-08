//
// Created by lsqy on 2020/8/8.
//

/* 1036 跟奥巴马一起编程 (15分)
 * 耗时：4:27.09
 *
 * 输出的行数实际上是列数的 50%（四舍五入取整）
 */

#include <iostream>

using namespace std;

int main(void) {
    int n, line;
    char ch;
    cin >> n >> ch;
    line = n/2.0+0.5;
    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || i == line-1) cout << ch;
            else if (j == 0 || j == n-1) cout << ch;
            else cout << " ";
        }
        cout << endl;
    }
    return 0;
}