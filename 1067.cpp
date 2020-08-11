//
// Created by lsqy on 2020/8/11.
//

/* 1067 试密码 (20分)
 * 耗时：32:15.26
 *
 * 1. 用户可能输入包含空格字符的尝试密码
 * 2. 测试点5：用户输入"#..."以"#"开头的尝试密码 （当读到一行只有单个 # 字符时，输入结束，并且这一行不是用户的输入。）
 */

#include <iostream>

using namespace std;

int main(void) {
//    对用户的每个输入，如果是正确的密码且尝试次数不超过 N，则在一行中输出 Welcome in，并结束程序；
//    如果是错误的，则在一行中按格式输出 Wrong password: 用户输入的错误密码；
//    当错误尝试达到 N 次时，再输出一行 ，并结束程序。
    string key, try_str;
    int cnt = 0, max_cnt;

    cin >> key >> max_cnt;
    getchar();
    while (getline(cin, try_str)) {
        if (try_str == "#") break;
        if (try_str == key) {
            cout << "Welcome in" << endl;
            break;
        }
        else {
            cnt++;
            cout << "Wrong password: " << try_str << endl;
            if (cnt >= max_cnt) {
                cout << "Account locked" << endl;
                break;
            }
        }
    }
    return 0;
}