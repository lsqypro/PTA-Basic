//
// Created by lsqy on 2020/8/9.
//

/* 1048 数字加密 (20分)
 * 耗时：29:29.68
 *
 * 1. B串被加密，B串小于A串时，B串需要在前面插入 与0加密的结果
 * 2. A串小于B串时，B串前面多余部分不变
 * 3. 总之加密后B串长度一定大于等于A串长度
 */

#include <iostream>

using namespace std;

int main(void) {
    string a_str, b_str;
    char ch_map[] = "0123456789JQK";

    cin >> a_str >> b_str;  // 输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。
    int length_a = a_str.size(), length_b = b_str.size();
    for (int i = 0; i < length_a; ++i) {
        int a_index = length_a-i-1, b_index = length_b-i-1;  // 从后往前
        int a = a_str[a_index]-'0';
        int b = 0;
        if (b_index >= 0) b = b_str[b_index]-'0';

        if ((i+1) % 2 != 0) {
            if (b_index >= 0) b_str[b_index] = ch_map[ (a+b)%13 ];
            else b_str.insert(0, 1, ch_map[ (a+b)%13] );
        }
        else {
            if (b_index >= 0) b_str[b_index] = ch_map[ (b-a+10)%10 ];
            else b_str.insert(0, 1, ch_map[ (b-a+10)%10 ]);
        }
    }
    cout << b_str << endl;
    return 0;
}