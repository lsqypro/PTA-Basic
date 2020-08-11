//
// Created by lsqy on 2020/8/11.
//

/* 1057 数零壹 (20分)
 * 耗时：18:53.40
 *
 */

#include <iostream>

using namespace std;

int main(void) {
    int zero = 0, one = 0;
    long long sum = 0;
    string str;

    getline(cin, str);
    for (int i = 0; i < str.length(); ++i) {
        if (isalpha(str[i])) sum += toupper(str[i])-'A'+1;
    }
    while (sum) {
        if (sum%2 == 0) zero++;
        else one++;
        sum /= 2;
    }
    cout << zero << " " << one << endl;
    return 0;
}