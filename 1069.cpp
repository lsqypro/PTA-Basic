//
// Created by lsqy on 2020/8/11.
//

/* 1069 微博转发抽奖 (20分)
 * 耗时：29:07.59
 *
 * 1. 判断中奖逻辑：cnt从1开始，特别注意cnt-s>=0
 *      (cnt-s) % n == 0 && cnt-s >= 0
 */

#include <iostream>
#include <map>

using namespace std;

int main(void) {
    int m, n, s;
    string nick;
    map<string, int> cnt_map;

    cin >> m >> n >> s;
    for (int i = 0, cnt = 1; i < m; ++i, cnt++) {
        cin >> nick;
        if ((cnt-s) % n == 0 && cnt-s >= 0) {
            if (cnt_map.find(nick) == cnt_map.end()) {
                cnt_map[nick] = 1;
                cout << nick << endl;
            } else cnt--;
        }
    }
    if (cnt_map.size() == 0) cout << "Keep going..." << endl;
    return 0;
}