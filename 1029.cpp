//
// Created by lsqy on 2020/8/7.
//

/* 1029 旧键盘 (20分)
 * 耗时：38:56.81
 */

#include <iostream>
#include <string>

using namespace std;
// 7_This_is_a_test
//  _ h s_ s_a_ es
// 7 T i  i    t  t
int main(void) {
    string str1, str2, str3;
    int alpha[26] = {0}, number[10] = {0}, _ch = 0;

    cin >> str1 >> str2;
    int i = 0, j = 0;
    while (i < str1.size()) {
        char ch1 = str1[i], ch2 = str2[j];
        if (ch1 != ch2) {
            if (isdigit(ch1) && number[ch1-'0']++ == 0) str3.push_back(ch1);
            else if (isalpha(ch1) && alpha[toupper(ch1)-'A']++ == 0) str3.push_back(toupper(ch1));
            else if (ch1 == '_' && _ch++ == 0) str3.push_back(ch1);
            i++;
        }
        else i++, j++;
    }
    cout << str3 << endl;
    return 0;
}