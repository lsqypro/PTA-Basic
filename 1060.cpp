//
// Created by lsqy on 2020/8/11.
//

/* 1060 爱丁顿数 (25分)
 * 耗时：58:01.84
 *
 * 1. E: 将输入的天数降序排序，以天数为x,距离为y做出函数图像 与 y=x的函数图像交点的X右侧离散值即为E
 * 2. 函数实现：将距离数组排序，在以destance[index]>days为条件递增e
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, e = 0;
    vector<int> destance;

    cin >> n;
    destance.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> destance[i];
    }
    sort(destance.begin(), destance.end());
    while (e < n && destance[n-1-e] > e+1) e++;  // 升序的数组从后往前为降序,e从0开始,而天数应该是e+1开始
    cout << e << endl;

    return 0;
}