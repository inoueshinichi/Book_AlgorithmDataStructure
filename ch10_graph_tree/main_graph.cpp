/**
 * @file main_graph.cpp
 * @author your name (you@domain.com)
 * @brief グラフ (データ構造)
 * @version 0.1
 * @date 2021-10-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <dirent.h> // mkdir
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// 1)
using Graph = vector<vector<int>>; // グラフ型

// 2) 重み付きの辺
struct Edge {
    int to; // 隣接頂点番号
    long long w; // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};
using WeightGraph = vector<vector<Edge>>; // 重み付きグラフ型


int main(int, char**) {

    // Graph
    {
        Graph G(8); // グラフ

        // 図10.12の有向グラフ
        G[0] = {5};
        G[1] = {3,6};
        G[2] = {5,7};
        G[3] = {0,7};
        G[4] = {1,2,6};
        G[5] = {};
        G[6] = {7};
        G[7] = {0};
    }

    
    // グラフを入力として受け取る
    {
        // 頂点数と辺数
        int N, M;
        printf("超点数: "); cin >> N;
        printf("辺数: "); cin >> M;

        // グラフ
        Graph G(N);
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            G[a].push_back(b);

            // 無向グラフの場合は以下を追加
            // G[b].push_back(a);
        }
    }

    
    // 重み付きグラフ
    {
        // 頂点数と辺数
        int N, M;
        printf("超点数: "); cin >> N;
        printf("辺数: "); cin >> M;

        // グラフ
        WeightGraph G(N);

        for (int i = 0; i < M; ++i) {
            int a, b;
            long long w;
            cin >> a >> b >> w;
            G[a].push_back(Edge(b, w));
        }
    }

}