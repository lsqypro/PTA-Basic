//
// Created by lsqy on 2020/8/9.
//

/* 1042 字符统计 (20分)
 * 耗时：6:20.91
 *
 */

#include <iostream>

using namespace std;

int main(void) {
    string str;
    int cnt = 0, ascii[128] = {0};
    char max;

    getline(cin, str);
//    统计时不区分大小写，输出小写字母
    for (int i = 0; i < str.length(); ++i) {
        char ch = tolower(str[i]);
        if (isalpha(ch)) {
            ascii[ch]++;
            if (ascii[ch] > cnt || (ascii[ch] == cnt && ch < max)) {
                max = ch;
                cnt = ascii[ch];
            }
        }
    }
    cout << max << " " << cnt << endl;
    return 0;
}