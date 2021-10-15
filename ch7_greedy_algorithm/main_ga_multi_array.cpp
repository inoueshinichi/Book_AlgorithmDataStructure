/**
 * @file main_ga_multi_array.cpp
 * @author your name (you@domain.com)
 * @brief 貪欲法　マルチ配列
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
using namespace std;


int main(int, char**) {
    // 入力
    cout << "配列の個数を指定してください" << endl;
    int N;
    cin >> N;

    vector<long long> A(N), B(N);

    for (int i =0; i <N; ++i) {
        printf("A[%d]: ", i);
        cin >> A[i];
        printf("B[%d]: ", i);
        cin >> B[i];
    }

    // 答え
    long long sum = 0;
    for (int i = N -1; i>=0; --i) {
        A[i] += sum; // 前回までの操作回数を足す
        long long amari = B[i] % A[i];
        long long D = 0;
        if (amari != 0) D = B[i] - amari;
        sum += D;
    }

    cout << "最小のボタン押し回数: " << sum << endl;
}