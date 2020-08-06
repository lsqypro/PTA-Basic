//
// Created by lsqy on 2020/8/5.
//

/* 1002 写出这个数 (20分)
 * 耗时：12:36.63
 */

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string in_str;
    string num_map[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    int sum = 0;

    cin >> in_str;
    for (size_t i = 0; i < in_str.size(); i++) {
        sum += in_str[i] - '0';
    }

    string out_str = to_string(sum);
    for (size_t i = 0; i < out_str.size(); i++) {
        cout << num_map[out_str[i]-'0'];
        if (i != out_str.size()-1) cout << " ";
    }

    return 0;
}