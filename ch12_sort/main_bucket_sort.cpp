/**
 * @file main_bucket_sort.cpp
 * @author your name (you@domain.com)
 * @brief バケットソート 0以上A未満の整数値のときO(N+A)を達成できる. クイックソートより早い場面がある.
 * @version 0.1
 * @date 2021-11-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000; // ここでは、配列の値は100000未満とする

// バケットソート
void BucketSort(vector<int>& a) {
    int N = (int)a.size();

    // 各要素の個数をカウントする(ヒストグラム)
    vector<int> num(MAX, 0);
    for (int i = 0; i < N; ++i) {
        ++num[a[i]]; // a[i]をカウントする
    }

    // numの累積和を取る(累積ヒストグラム)
    // sum[v]: v以下の値の個数
    // 値 a[i]が全体の中で何番目に小さいかを求める
    vector<int> sum(MAX, 0);
    // sum[0] = num[0]; // これが抜けている気がする
    for (int v = 1; v < MAX; ++v) {
        sum[v] = sum[v-1] + num[v];
    }

    // 累積ヒストグラム(sum)を元にソート処理
    // a2: aをソートしたもの
    vector<int> a2(N);
    for (int i = N-1; i>=0; --i) {
        a2[--sum[a[i]]] = a[i]; // ここの処理のイメージがつかない.
    }

    a = a2;
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

    // バケットソート
    BucketSort(a);
    showArray(a);
    return 0;
}