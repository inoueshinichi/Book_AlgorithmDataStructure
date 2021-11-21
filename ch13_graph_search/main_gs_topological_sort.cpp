/**
 * @file main_gs_topological_sort.cpp
 * @author your name (you@domain.com)
 * @brief 深さ優先探索の帰りがけ順によるトポロジカルソート
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;


void rec (const Graph& G, int v, vector<bool>& seen, vector<int>& order) {
    seen[v] = true;

    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        rec(G, next_v, seen, order);
    }

    // v-out(帰りがけ順)を記録する
    order.push_back(v);
}

// トポロジカルソート
void topological_sort(const Graph& G, vector<int>& order) {
    vector<bool> seen;
    seen.assign(G.size(), false); // 初期化(未訪問)
    order.clear();

    for (int v = 0; v < G.size(); ++v) {
        if (seen[v]) continue; // 既に訪問済みなら探索しない
        rec(G, v, seen, order);
    }

    reverse(order.begin(), order.end()); // 逆順
}


int main(int, char**) {

    // 超点数
    int N = 8;

    // グラフ
    Graph G(N);

    printf("有効グラフ\n");
    G[0].push_back(5);
    G[1].push_back(3);
    G[1].push_back(6);
    G[2].push_back(5);
    G[2].push_back(7);
    G[3].push_back(0);
    G[3].push_back(7);
    G[4].push_back(1);
    G[4].push_back(2);
    G[4].push_back(6);
    // G[5].push_back();
    G[6].push_back(7);
    G[7].push_back(0);


    vector<int> sorted_order;

    // トポロジカルソート
    topological_sort(G, sorted_order);

    for (auto v : sorted_order) {
        cout << v << " ->";
    }
    cout << endl;
}
