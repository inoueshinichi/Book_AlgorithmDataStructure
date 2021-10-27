/**
 * @file main_uf_get_group_of_graph.cpp
 * @author your name (you@domain.com)
 * @brief UnionFindを用いてグラフの連結成分の個数を調べる
 * @version 0.1
 * @date 2021-10-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

// Union-Find
struct UnionFind
{
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    // 根を求める
    int root (int x) {
        if (par[x] == -1) return x; // xが根の場合直接返す
        else return par[x] = root(par[x]);
    }

    // xとyが同じグループに属するかどうか(根が一致するかどうか)
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // xを含むグループとyを含むグループを併合する
    bool unite(int x, int y) {
        // x, yをそれぞれ根まで移動する
        x = root(x); y = root(y);

        // すでに同じグループのときは何もしない
        if (x == y) return false;

        // union by size(y側のサイズが小さくなるようにする)
        if (siz[x] < siz[y]) swap(x, y);

        // yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // xを含むグループのサイズ
    int size(int x) {
        return siz[root(x)];
    }
};


int main(int, char**)
{
    // 頂点数
    std::cout << "頂点数"; int N; std::cin >> N;

    // 辺数
    std::cout << "辺数"; int M; std::cin >> M;

    UnionFind uf(N);

    // 各辺に対する処理
    for (int i = 0; i < M; ++i) {
        int a, b;
        cout << "u: "; cin >> a;
        cout << "v: "; cin >> b;

        // if (a >= N || b >= N) {
        //     std::cout << "スキップします" << std::endl;
        //     i -= 1;
        //     continue;
        // }

        uf.unite(a, b); // aを含むグループとbを含むグループ
    }


    // 集計
    int res = 0;

    for (int x = 0; x < N; ++x) {
        if (uf.root(x) == x) ++res;
    }

    std::cout << "グラフの連結成分の個数: " << res << std::endl;
}