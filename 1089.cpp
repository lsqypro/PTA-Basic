//
// Created by lsqy on 2020/8/13.
//

/* 1089 狼人杀-简单版 (20分)
 * 耗时：01:22:22.24
 *
 * 1. 使用过数字判断真假的思维：
 *      同正异负：即预言的情况和实际的情况相同则两数相乘为正号，否则为负号
 */

#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> &v, int i, int j) {
    // 假设i,j为狼人成立便返回true

    // flag标记数组，1为好人，-1为狼人
    vector<int> flag(v.size(), 1);
    flag[i] = flag[j] = -1;

    vector<int> lie_id;  // 说谎人的序号
    for (int k = 1; k < v.size(); ++k) {
        // 判断k是否说谎
        int id = abs(v[k]);
        if (v[k] * flag[id] < 0) lie_id.push_back(k);
    }
    // flag[lie_id[i]]的累加和表征了：好人数-狼人数（一个狼人贡献-1,一个好人贡献1）
    // flag[ lie_id[0] ] + flag[ lie_id[1] ] ：2（两个好人说谎），0（一个狼人，一个好人说谎），-2（两个狼人说谎）
    if (lie_id.size() == 2 && (flag[ lie_id[0] ] + flag[ lie_id[1] ] == 0) ) return true;
    return false;
}

int main(void) {
    int n;
    vector<int> v;

    cin >> n;
    v.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    // check
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (check(v, i, j)) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;
    return 0;
}
