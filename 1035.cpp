//
// Created by lsqy on 2020/8/8.
//

/* 1035 插入与归并 (25分)
 * 耗时：51:22.81
 *
 * 1. 方法1，写出插入排序 和 循环方式的归并排序，在每一轮结束时 判断上一轮的结果（此时数组内容就是arr2再执行一遍的结果）
 * 2. 方法2，先判断是否为插入排序，非此即彼
 *    归并算法给定length=2并按（length *= 2）递增，以length为间隔判断arr2是否有序
 *    当以length判断为无序时，当前length即为arr2再进行一次归并的长度，按此长度分段sort即可
 */

#include <iostream>
#include <string>

using namespace std;

int n;
int arr1[100], arr2[100], arr[100];

bool check_arr(int *arr1, int *arr2) {
    for (int k = 0; k < n; ++k) {
        if (arr1[k] != arr2[k]) {
            return false;
        }
    }
    return true;
}

bool is_insert_sort() {
    // copy
    for (int l = 0; l < n; ++l) {
        arr[l] = arr1[l];
    }
    // insert sort
    bool ans = false;
    for (int i = 1; i < n; ++i) {  // 插入排序从第二个数（i = 1）开始，否则测试点2不通过
        int tmp = arr[i], j = i;
        for (; j > 0 && arr[j - 1] > tmp; --j)  // 递增排序
            arr[j] = arr[j - 1];
        arr[j] = tmp;
        // 完成一次排序，与arr2比较是否相同
        if (ans) break;
        ans = check_arr(arr, arr2);
    }
    return ans;
}

void merge(int *arr, int *tmp, int begin, int center, int end) {
    // merge
    int left = begin, right = center, index = begin;
    while (left < center && right < end) {
        if (arr[left] <= arr[right]) tmp[index++] = arr[left++];
        else tmp[index++] = arr[right++];
    }
    while (left < center) tmp[index++] = arr[left++];
    while (right < end) tmp[index++] = arr[right++];
    while (begin < end) {
        arr[begin] = tmp[begin];
        begin++;
    }
}

void merge_pass(int *arr, int *tmp, int length) {
    int i = 0;
    for (; i + 2 * length <= n; i += 2 * length) {
        merge(arr, tmp, i, i+length, i + 2 * length);
    }
    if (i + length < n) {
        merge(arr, tmp, i, i + length, n);
    }
    // i + length >= n 直接追加到后面
}

bool is_merge_sort() {
    // copy
    for (int i = 0; i < n; ++i) {
        arr[i] = arr1[i];
    }

    // merge sort
    int *tmp = new int[n];
    int length = 1;
    bool ans = false;
    while (length < n) {
        merge_pass(arr, tmp, length);
        if (ans) break;
        ans = check_arr(arr, arr2);
        length *= 2;
    }
    delete [] tmp;
    return ans;
}

int main(void) {
    // input
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }

    // check an calculate
    if (is_merge_sort()) {
        cout << "Merge Sort" << endl;
    }
    else {
        is_insert_sort();
        cout << "Insertion Sort" << endl;
    }
    // output
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) cout << " ";
        else cout << endl;
    }

    return 0;
}