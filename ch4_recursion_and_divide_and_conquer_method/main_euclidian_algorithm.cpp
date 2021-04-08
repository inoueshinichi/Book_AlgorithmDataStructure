/**
 * @file main_euclidian_algorithm.cpp
 * @author your name (you@domain.com)
 * @brief ユークリッドの互除法 O(logN)
 * @version 0.1
 * @date 2021-04-07
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

// ユークリッド互除法によって最大公約数を求める
int GCD(int m, int n)
{
    if (n == 0)
        return m;
    
    // 再帰呼び出し
    return GCD(n, m % n);
}


int main(int argc, char** argv)
{
    int N, M;
    std::cout << "Input: " << std::endl;
    std::cout << "N: ";
    std::cin >> N;
    std::cout << "M: ";
    std::cin >> M;
    std::printf("N: %d, M: %d \n", N, M);

    auto start = high_resolution_clock::now();

    // 最大公約数
    std::printf("GCD(%d,%d)=%d\n", N, M, GCD(N, M));
    // std::printf("GCD(%d,%d)=%d\n", N, M, GCD(15, 51));

    auto end = high_resolution_clock::now();
    auto duration = end - start;
    double duration_us = duration_cast<microseconds>(duration).count();
    std::cout << duration_us << "[us]" << std::endl;
    

    return 0;
}