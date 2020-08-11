//
// Created by lsqy on 2020/8/11.
//

/* 1070 结绳 (25分)
 * 耗时：24:24.51
 *
 * 1. 最先将最小的两段绳合并，最后合并最大的两段(最先折叠的绳子折叠次数越多)
 * 2. 将输入的绳长升序排列，优先合并小序号段，使用递归的方式：begin起始下标，end终止下标,终止条件begin==end,不折叠
 *      double fold(int begin, int end) {
            if (begin == end) return v[begin];
            return (fold(begin, end-1) + v[end])/2;
        }
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

double fold(int begin, int end) {
    if (begin == end) return v[begin];
    return (fold(begin, end-1) + v[end])/2;
}

int main(void) {
    int n, sum = 0;

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sum = fold(0, v.size()-1);
    cout << sum << endl;

    return 0;
}