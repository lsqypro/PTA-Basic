//
// Created by lsqy on 2020/8/8.
//

/* 1033 旧键盘打字 (20分)
 * 耗时：21:21.27
 *
 * 1. 特别注意题目说：题目保证第 2 行输入的文字串非空，暗示第 1 行可能为空，事实上测试点2就是为空的
 */

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string in_str, out_str, key_str;
    getline(cin, key_str);
    getline(cin, in_str);
    for (int i = 0; i < in_str.size(); ++i) {
        char ch = in_str[i];
        if (isupper(ch)) {
            if (key_str.find(ch) > key_str.size() && key_str.find('+') > key_str.size()) out_str.push_back(ch);
        }
        else {
            if (key_str.find(toupper(ch)) > key_str.size()) out_str.push_back(ch);
        }
    }
    cout << out_str << endl;  // 测试点1：输出空行
    return 0;
}