//
// Created by lsqy on 2020/8/13.
//

/* 1086 就不告诉你 (15分)
 * 耗时：04:33.77
 *
 * 1. 注意类似100 的反序应输出 1
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    string ans = to_string(a*b);
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.length(); ++i) {
        if (ans[i] != '0') {
            ans = ans.substr(i, ans.size());
            break;
        }
    }

    if (ans[0] == '0') cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}
