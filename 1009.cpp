//
// Created by lsqy on 2020/8/6.
//

/* 1009 说反话 (20分)
 * 耗时：9:12.86
 */
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    getline(cin, str);
    while (str.size()) {
        int pos = str.rfind(" ");
        if (pos == -1) {
            cout << str;
            break;
        }
        cout << str.substr(pos + 1, str.size()) << " ";
        str = str.substr(0, pos);
    }

    return 0;
}