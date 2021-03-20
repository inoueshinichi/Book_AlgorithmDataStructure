/**
 * @file for.cpp
 * @author your name (you@domain.com)
 * @brief for文 O(N), O(N^2)
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 * Tips
 * O(N^2): データ数が10万以内であれば、実時間で終わる
 */

#include <iostream>
#include <chrono>
using namespace std::chrono;

int main(int,char**)
{
    int N;
    std::cout << "Input: ";
    std::cin >> N;
    std::cout << "Data size: " << N << std::endl;

    auto start = high_resolution_clock::now();

    // 一重ループ O(N)
    int count = 0;
    for (int i = 0; i < N; ++i) {
        ++count;
    }
    auto end = high_resolution_clock::now();
    auto duration = end - start;
    double duration_ms = duration_cast<milliseconds>(duration).count();
    std::cout << duration_ms << "[ms]" << std::endl;

    // 二重ループ O(N^2): データ数が10万以内であれば、実時間で終わる
    start = high_resolution_clock::now();
    count = 0;
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            ++count;
        }
    }
    end = high_resolution_clock::now();
    duration = end - start;
    duration_ms = duration_cast<milliseconds>(duration).count();
    std::cout << duration_ms << "[ms]" << std::endl;

    return 0;
}