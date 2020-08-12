//
// Created by lsqy on 2020/8/12.
//

/* 1076 Wifi密码 (15分)
 * 耗时：05:32.57
 *
 */

#include <iostream>

using namespace std;

int main(void) {
    int n;
    string ans;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            char q, a;
            scanf(" %c-%c", &q, &a);
            if (a == 'T') ans.push_back(q-'A'+1+'0');
        }
    }
    cout << ans << endl;
    return 0;
}