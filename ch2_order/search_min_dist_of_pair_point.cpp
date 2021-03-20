/**
 * @file search_min_dist_of_pair_point.cpp
 * @author your name (you@domain.com)
 * @brief 最近点対問題 O(N^2)
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 * Tips
 * nC2 = n(n-1)/2 = 0.5 * n^2 - 0.5 * n
 */
#include <vector>
#include <cmath>
#include <random>

#include <iostream>
#include <chrono>
using namespace std::chrono;


int main(int,char**)
{
    int N;
    std::cout << "Input: ";
    std::cin >> N;
    std::cout << "Data size: " << N << std::endl;

    auto calc_dist = [](auto xs, auto ys, auto xe, auto ye) -> double 
    {
        return std::sqrt((xs - xe) * (xs - xe) + (ys - ye) * (ys - ye));
    };

    // N個のデータを準備
    std::seed_seq seed{20210320};
    std::mt19937_64 engin(seed);
    std::uniform_real_distribution<double> dist(0, N);
    std::vector<double> x(N), y(N);
    for (int i = 0; i < N; ++i) {
        x.at(i) = y.at(i) = dist(engin);
        std::cout << "(x,y)=(" << x.at(i) << "," << y.at(i) << ")" << std::endl;
    }

    // 求める値を十分大きい値で初期化しておく.
    double min_dist = 1000000000.0;

    auto start = high_resolution_clock::now();

    // 最近点対問題
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // (x[i],y[i])と(x[j],y[j])の距離
            double dist_i_j = calc_dist(x[i],y[i],x[j],y[j]);

            // 暫定最小値
            if (dist_i_j < min_dist) {
                min_dist = dist_i_j;
            }
        }
    }
    std::cout << "min_dist: " << min_dist << std::endl;
    auto end = high_resolution_clock::now();
    auto duration = end - start;
    double duration_ms = duration_cast<milliseconds>(duration).count();
    std::cout << duration_ms << "[ms]" << std::endl;

    return 0;
}
