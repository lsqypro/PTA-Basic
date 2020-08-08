//
// Created by lsqy on 2020/8/8.
//

/* 1031 查验身份证 (15分)
 * 耗时：12:29.71
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char map[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    vector<string> ids;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string id;
        cin >> id;
        //    加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；然后将计算的和对11取模得到值Z
        int w = 0;
        for (int j = 0; j < 17; ++j) {
            w += weight[j] * (id[j]-'0');
        }
        if (map[w%11] != id[17])
            ids.push_back(id);
    }
    if (ids.empty()) cout << "All passed" << endl;
    for (int k = 0; k < ids.size(); ++k) {
        cout << ids[k] << endl;
    }
    return 0;
}