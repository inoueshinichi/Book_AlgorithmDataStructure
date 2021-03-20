/**
 * @file pick_up_even.cpp
 * @author your name (you@domain.com)
 * @brief 偶数の列挙
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 * Tips
 * 
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

    // 偶数の列挙
    for (int i = 2; i <= N; i += 2) {
        std::cout << i << std::endl;
    }

    auto end = high_resolution_clock::now();
    auto duration = end - start;
    double duration_ms = duration_cast<milliseconds>(duration).count();
    std::cout << duration_ms << "[ms]" << std::endl;

    return 0;
}