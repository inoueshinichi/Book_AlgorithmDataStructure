/**
 * @file main_quick_sort.cpp
 * @author your name (you@domain.com)
 * @brief クイックソート min O(NlogN) max O(N^2) In-place, No-stable
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
void QuickSort(vector<int>& a, int left, int right) {

    // ベース条件
    if (right - left <= 1) return;

    int pivot_index = (left + right) / 2; // 適当に中点を選ぶ
    int pivot = a[pivot_index];
    swap(a[pivot_index], a[right-1]); // pivotと右端をスワップ

    int i = left; // iは左詰めされたpivot未満要素の右端を表す
    for (int j = left; j < right - 1; ++j) {
        if (a[j] < pivot) { // pivot未満のものがあったら左に詰めていく
            swap(a[i++], a[j]);
        }
    }
    swap(a[i], a[right-1]); // pivotを適切な場所に挿入

    // 再帰的に解く
    QuickSort(a, left, i); // 左半分(pivot未満)
    QuickSort(a, i + 1, right); // 右半分(pivot以上)
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

    // クイックソート
    QuickSort(a, 0, (int)a.size());
    showArray(a);

}