//
// Created by lsqy on 2020/8/9.
//

/* 1045 快速排序 (25分)
 * 耗时：01:49:46.50
 *
 * 1. 快速排序思想（对于非递减排序）：一个元素左侧元素都比它小，右侧元素都比它大，那这个元素的位置为完全排序后的位置
 * 2. 遍历数组时，可用变量记录当前元素之前的最大值
 * 3. N 个不同的正整数：当前位置元素比之前的最大值大，且与排序后的位置相同，则可断定当前元素小于之后的所有元素
 * 4. 对于卡超时题目，涉及大量输入输出时使用scanf,printf（4ms,44ms,20ms,34ms,40ms,39ms）比cin,cout(3ms,87ms,56ms,113ms,102ms,99ms)快许多
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> seq, key, out;
    int n, l_max = 0;

    scanf(" %d", &n);
    seq.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &seq[i]);
    }

    key = seq;
    sort(key.begin(), key.end());
    for (int i = 0; i < n; ++i) {
        if (seq[i] > l_max) {
            l_max = seq[i];
            if (seq[i] == key[i]) out.push_back(key[i]);
        }
    }

    printf("%d\n", out.size());
    for (int i = 0; i < out.size(); ++i) {
        printf("%d", out[i]);
        if (i != out.size() - 1) printf(" ");
    }
    printf("\n");
    return 0;
}