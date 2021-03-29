/**
 * @file main_liear_search.cpp
 * @author your name (you@domain.com)
 * @brief 線形探索法
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
    int v;
    v = N;
    std::vector<int> a(N);
    std::seed_seq seed {20210320};
    std::mt19937_64 engin(seed);
    std::uniform_int_distribution<> dist(0, N);
    for (int i = 0; i < N; ++i) {
        a.at(i) = dist(engin);
        std::printf("a[%d]=%d\n", i, a.at(i));
    }

    auto start = high_resolution_clock::now();

    // 線形探索
    int found_id = -1; // 初期値はありえない数値.
    int min_value = INF;
    for (int i = 0; i < N; ++i) {
        if (a[i] < min_value)
            min_value = a[i];

        if (a[i] == v) {
            found_id = i;
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = end - start;
    double duration_us = duration_cast<microseconds>(duration).count();
    std::cout << duration_us << "[us]" << std::endl;

    std::cout << "Found?: " << found_id << std::endl;
    std::cout << "Min value: " << min_value << std::endl;
    return 0;
}