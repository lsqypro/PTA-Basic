//
// Created by lsqy on 2020/8/6.
//

/* 1011 A+B 和 C (15分)
 * 耗时：4:58.86
 *
 */
#include <iostream>

using namespace std;

int main(void) {
    long a, b, c;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        cout << "Case #" << i + 1 << ": " << (a+b>c? "true" : "false") << endl;
    }
    return 0;
}