//
// Created by lsqy on 2020/8/12.
//

/* 1078 字符串压缩与解压 (20分)
 * 耗时：16:18.96
 *
 */

#include <iostream>

using namespace std;

int main(void) {
    char opt;
    string str, ans;

    cin >> opt;
    getchar();
    getline(cin, str);
    if (opt == 'C') {
        // 压缩；
        int cnt = 0;
        char old = str[0];
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == old) cnt++;
            else {
                if (cnt == 1) ans += old;
                else if (cnt > 1) ans += to_string(cnt) + old;
                old = str[i];
                cnt = 0;
                i--;
            }
        }
        if (cnt == 1) ans += old;
        else if (cnt > 1) ans += to_string(cnt) + old;
    }
    else if (opt == 'D') {
        string num_str;
        for (int i = 0; i < str.length(); ++i) {
            if (isdigit(str[i])) num_str += str[i];
            else {
                int cnt = 1;
                if (!num_str.empty()) cnt = stoi(num_str);
                num_str.clear();
                ans += string().insert(0, cnt, str[i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}