/**
 * @file main_merge_sort.cpp
 * @author your name (you@domain.com)
 * @brief マージソート min O(NlogN) max O(NlogN), No-Inplace(外部メモリ必要数N), Stable
 * @version 0.1
 * @date 2021-10-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

// 配列aの区間[left,right)をソートする
void MergeSort(vector<int>& a, int left, int right) {

    // ベース条件
    if (right - left == 1) return;

    int mid = left + (right - left) / 2;

    // 左半分 [left,mid)をソート
    MergeSort(a, left, mid);

    // 右半分 [mid, right)をソート
    MergeSort(a, mid, right);

    
    // 一旦、左と右のソート結果をコピーしておく。(右側は左右反転)
    vector<int> buf;
    for (int i = left; i < mid; ++i) buf.push_back(a[i]);
    for (int i = right - 1; i >= mid; --i) buf.push_back(a[i]);

    // 併合する
    int index_left = 0;
    int index_right = (int)buf.size() - 1;
    for (int i = left; i < right; ++i) {
        // 左側採用
        if (buf[index_left] <= buf[index_right]) {
            a[i] = buf[index_left++];
        }
        // 右側採用
        else {
            a[i] = buf[index_right--];
        }
    }
}


void showArray(vector<int>& a) {
    ostringstream oss;
    for (int i = 0; i < (int)a.size(); ++i) {
        oss << a[i] << " ";
    }
    cout << oss.str() << endl;
}


int main(int, char**) {

    // 入力
    int N;
    cout << "要素数を入力してください ";
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    showArray(a);
    cout << "--------" << endl;

    // マージソート
    MergeSort(a, 0, (int)a.size());
    showArray(a);

}