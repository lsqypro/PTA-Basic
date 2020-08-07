//
// Created by lsqy on 2020/8/7.
//

/* 1024 科学计数法 (20分)
 * 耗时：54:30.98
 *
 * 1. 数字的整数部分只有 1 位，小数部分至少有 1 位，该数字及其指数部分的正负号即使对正数也必定明确给出。
 * 2. 保证所有有效位都被保留。
 * 3. 该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。(存储长度不超过 9999 字节：使用string保存)
 * 4. 过程中遇到个运行时错误：basic_string::_M_create
terminate called after throwing an instance of 'std::length_error'
  what():  basic_string::_M_replace_aux
 * 原因是：string.insert(a, b, 'c'); 时 b 为负数而出错
 */

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string source, target;
    cin >> source;
    target.push_back(source[1]);  // 整数部分只有 1 位
    int i = 3;  // 小数部分
    for (; i < source.size(); ++i) {
        if (source[i] != 'E') {
            target.push_back(source[i]);
        }
        else break;
    }
    i++;  // 指数部分的正负号即使对正数也必定明确给出。
    int len = stoi(&source[i+1]);
    int size = target.size();
    if (source[i] == '+') {
        // 小数点向右移 target: 12
        for (int j = 0; j < (len + 1 - size); ++j) {
            target.push_back('0');
        }
        if (target.size() > len + 1)
            target.insert(1 + len, 1, '.');
    }
    else {
        // 小数点向左移 123400
        target.insert(0, len-1, '0');
        if (len > 0)
            target.insert(0, "0.");
    }

    if (source[0] == '-')
        cout << "-";
    cout << target << endl;

    return 0;
}