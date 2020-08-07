//
// Created by lsqy on 2020/8/7.
//

/* 1023 组个最小数 (20分)
 * 耗时：16:57.28
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> arr;
    int num;
    string ret;

    for (int i = 0; i < 10; ++i) {
        cin >> num;
        for (int j = 0; j < num; ++j) {
            arr.push_back(i);
        }
    }
    sort(arr.begin(), arr.end());
//    至少拥有 1 个非 0 的数字。
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        if (*it != 0) {
            ret.push_back((*it)+'0');
            arr.erase(it);
            break;
        }
    }
    for (int j = 0; j < arr.size(); ++j) {
        ret.push_back(arr[j]+'0');
    }
    cout << ret << endl;
    return 0;
}