/**
 * @file main_mst_kruskal.cpp
 * @author your name (you@domain.com)
 * @brief 最小全域木問題: クラスカル法
 * @version 0.1
 * @date 2022-02-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief クラスカル法・・・貪欲法の一つ
 * step1: 各辺eの重みw(e)を昇順ソート
 * step2: 重みw(e)を持つ辺(u,v)を全域木集合Tに追加
 * step3: サイクルができなければ、承認. サイクルができれば(u,v)の追加を却下
 * Tは最小全域木になる.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Union-Findによる全域木の作成
struct UnionFind
{
    vector<int> par, siz;

    // 初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    // 根を求める
    int root(int x) {
        if (par[x] == -1) return x; // xが根の場合
        else return par[x] = root(par[x]); // 経路圧縮
    }

    // xとyが同じグループに属するかどうか(根が一致するかどうか)
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // xを含むグループとyを含むグループを併合する
    bool unite(int x, int y) {
        // それぞれの根まで移動する
        x = root(x), y = root(y);

        // 同じグループに属する場合何もしない
        if (x == y) return false;

        // union by size (y側のサイズが小さくなるようにする)
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


// 辺 e = (u,v)を {w(e), {u,v}} で表す
using Edge = pair<int, pair<int, int>>;

int main(int, char**)
{
    // 辺集合
    int M = 12; // 辺数
    vector<Edge> edges(M);
    edges[0] = Edge(9, make_pair(4, 2)); // {9, {4, 2}}
    edges[1] = Edge(2, make_pair(4, 6)); // {2, {4, 6}}
    edges[2] = Edge(4, make_pair(4, 1)); // {4, {4, 1}}
    edges[3] = Edge(3, make_pair(1, 6)); // {3, {1, 6}}
    edges[4] = Edge(5, make_pair(2, 7)); // {5, {2, 7}}
    edges[5] = Edge(7, make_pair(6, 7)); // {7, {6, 7}}
    edges[6] = Edge(8, make_pair(1, 3)); // {8, {1, 3}}
    edges[7] = Edge(6, make_pair(3, 7)); // {6, {3, 7}}
    edges[8] = Edge(10, make_pair(2,5)); // {10,{2, 5}}
    edges[9] = Edge(3, make_pair(7, 0)); // {3, {7, 0}}
    edges[10]= Edge(5, make_pair(3, 0)); // {5, {3, 0}}
    edges[11]= Edge(6, make_pair(0, 5)); // {6, {0, 5}}

    // 各辺を辺の重みが小さい順にソートする
    // pairはデフォルトで(第一要素, 第二要素)の辞書順比較
    sort(edges.begin(), edges.end());

    // クラスカル法
    long long res = 0;
    int N = 8; // 頂点数
    UnionFind uf(N);
    for (int i = 0; i < M; ++i) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        // 辺(u, v)の追加によってサイクル化形成されるときは追加しない
        if (uf.issame(u, v)) continue;

        // 辺(u, v)を追加する
        res += w;
        uf.unite(u, v);
    }

    cout << "最小全域木のコスト=" << res << endl; 
}