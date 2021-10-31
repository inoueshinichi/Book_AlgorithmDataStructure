/**
 * @file main_insertion_sort.cpp
 * @author your name (you@domain.com)
 * @brief 挿入ソート min O(N^2) max O(N^2) In-place, Stable
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

// 配列aをソートする
void InsertionSort(vector<int>& a) {
    int N = (int)a.size();
    for (int i = 1; i < N; ++i) {
        int v = a[i]; // 挿入したい値

        // vを挿入する適切な場所jを探す
        int j = i;
        for (; j > 0; --j) {
            if (a[j-1] > v) { // vより大きいものは1つ後ろに移す
                a[j] = a[j-1];
            }
            else break; // v以下になったら止める
        }
        a[j] = v; // 最後にj番目にvを持ってくる
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

    // 挿入ソート
    InsertionSort(a);
    showArray(a);
}