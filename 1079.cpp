//
// Created by lsqy on 2020/8/12.
//

/* 1079 延迟的回文数 (20分)
 * 耗时：32:34.54
 *
 *  1. 可能输入数字为 010
 *      010
        010 is a palindromic number.
 *  2. 可能输入数字为 100，反转后输出001
 *      100
        100 + 001 = 101
        101 is a palindromic number.
 *  3. 综上最好使用字符串处理
 */

#include <iostream>
#include <algorithm>

using namespace std;

bool is_palindromic(string str) {
    int i1 = 0, i2 = str.length()-1;
    while (i1 < i2) {
        if (str[i1++] != str[i2--]) return false;
    }
    return true;
}

string my_add(string a, string b) {
    string ret;
    int carry = 0;
    for (int i = 0; i < a.length(); ++i) {
        int ai = a[a.length()-1-i]-'0';
        int bi = b[a.length()-1-i]-'0';

        ret.insert(0, 1, (ai+bi+carry)%10+'0');
        carry = (ai + bi + carry) / 10;
    }
    if (carry) ret = "1" + ret;
    return ret;
}

int main(void) {
    string num;

    cin >> num;
    for (int i = 0; i <= 10; ++i) {
        if (is_palindromic(num)) {
            cout << num << " is a palindromic number." << endl;
            break;
        }
        else if (i == 10) {
            //    如果 10 步都没能得到回文数
            cout << "Not found in 10 iterations." << endl;
            break;
        }
        string a = num;
        string b = num;
        reverse(b.begin(), b.end());
        num = my_add(a, b);
        cout << a << " + " << b << " = " << num << endl;
    }

    return 0;
}


