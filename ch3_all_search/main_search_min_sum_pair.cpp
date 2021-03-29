/**
 * @file main_search_min_sum_pair.cpp
 * @author your name (you@domain.com)
 * @brief ペア和の最小値を求める(K以上の範囲) O(N^2)
 * @version 0.1
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <random>
#include <numeric>
using namespace std::chrono;

const int INF = 200'000'000; // 十分に大きな値

int main(int, char**)
{
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

    // 線形探索(ペア和の最小値を求める)
    int min_value = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // 和がK未満の場合、捨てる
            if (a[i] + b[j] < K) {
                continue;
            }

            // 最小値を更新
            if (a[i] + b[j] < min_value) {
                min_value = a[i] + b[j];
            }
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = end - start;
    double duration_us = duration_cast<microseconds>(duration).count();
    std::cout << duration_us << "[us]" << std::endl;

    std::cout << "min_value: " << min_value << std::endl;

    return 0;
}