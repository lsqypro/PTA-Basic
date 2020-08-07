//
// Created by lsqy on 2020/8/7.
//

/* 1021 个位数统计 (15分)
 * 耗时：3:10.98
 */

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    int cnt[10] = {0};
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        cnt[str[i]-'0']++;
    }
    for (int j = 0; j < 10; ++j) {
        if (cnt[j] != 0) cout << j << ":" << cnt[j] << endl;
    }
    return 0;
}