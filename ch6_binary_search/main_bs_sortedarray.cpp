/**
 * @file main_bs_sorted_array.cpp
 * @author your name (you@domain.com)
 * @brief ソート済みの配列に対して2分探索をする
 * @version 0.1
 * @date 2021-09-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <vector>
#include <iostream>
#include <initializer_list>



// 目的の値keyの添字を返す(存在しない場合、-1)
int binary_search(int key, const std::vector<int> &a) {
    int left = 0, right = a.size() - 1; // 配列aの左端と右端
    while (right >= left) {
        int middle = int(right + left / 2);
        if (a[middle] == key) return middle;
        else if (a[middle] < key) left = middle + 1;
        else if (a[middle] > key) right = middle - 1;
    }
    return -1;
}

#define BINARY_SEARCH(k, a) std::cout << binary_search(k, a) << std::endl

int main(int, char**) {

    // ソート済み配列
    const int N = 8;
    std::vector<int> a(N, 0);
    a[0]=3; a[1]=5; a[2]=8; a[3]=10; a[4]=14; a[5]=17; a[6]=21; a[7]=39;

    BINARY_SEARCH(10, a); // 3
    BINARY_SEARCH(3, a);  // 0
    BINARY_SEARCH(39, a); // 7
    BINARY_SEARCH(-1, a); // -1
    BINARY_SEARCH(9, a);  // -1
    BINARY_SEARCH(40, a); // -1

    return 0;    
}