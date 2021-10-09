/**
 * @file main_bs_pair_sum.cpp
 * @author your name (you@domain.com)
 * @brief 二分探索法によるペア和の最小値を求める O(N^2) -> O(NlogN)
 * @version 0.1
 * @date 2021-10-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm> // sort(), lower_bound()
#include <cmath>
#include <random>
#include <numeric>
#include <chrono>
using namespace std::chrono;
using namespace std;
const int INF = 200'000'000; // 十分に大きな値
// const int INF = 200000000; // 十分に大きな数

int main(int, char**) {

    // 入力
    int N;
    std::cout << "Input: ";
    std::cin >> N;
    std::cout << "Data size: " << N << std::endl;

    // N個のデータを準備
    int K;
    std::cout << "K: ";
    std::cin >> K;
    std::cout << K << std::endl;
    std::vector<int> a(N), b(N);
    std::seed_seq seed {20210320};
    std::mt19937_64 engin(seed);
    std::uniform_int_distribution<> dist(0, N);
    for (int i = 0; i < N; ++i) {
        a.at(i) = dist(engin);
        b.at(i) = dist(engin);
        std::printf("a[%d]=%d, b[%d]=%d\n", i, a.at(i), i, b.at(i));
    }

    auto start = high_resolution_clock::now();

    // binary searchでペア和の最小値を求める
    int min_value = INF;
    for (int i = 0; i < N; ++i) { // a[i]を固定

        // bの中でK-a[i]以上の範囲での最小値をしめるイテレータ
        auto iter = lower_bound(b.begin(), b.end(), K - a[i]);

        // イテレータの示す値
        int val = *iter;

        if (a[i] + val < min_value) {
            min_value = a[i] + val;
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = end - start;
    double duration_us = duration_cast<microseconds>(duration).count();
    std::cout << duration_us << "[us]" << std::endl;

    std::cout << "min_value: " << min_value << std::endl;
}