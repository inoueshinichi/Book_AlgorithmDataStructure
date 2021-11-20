/**
 * @file main_gs_bipartite_graph.cpp
 * @author your name (you@domain.com)
 * @brief 無効グラフが二部グラフ(白色の頂点同士が隣接せず、黒色の頂点同士も隣接しないようなグラフ)
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;


/**
 * @brief 二部グラフの判断の仕方
 * 
 * step1: グラフGの1つの頂点vを選び、vを白(黒)に塗る
 * step2: vの隣接する頂点に黒(白)を塗る
 * step3: vの隣接する頂点に対してstep1-step2を繰り返す
 * step4: もしstep3の過程で「両端点が同色である辺」が検出されれば、二部グラフではない.
 */


// 深さ優先探索による二部グラフの判定
vector<int> color; // -1: 未探索, 0: 白, 1: 黒
bool DFS(const Graph& G, int v, int cur = 0) {
    color[v] = cur; // 白/黒で塗る
    for (auto next_v : G[v]) {
        // 隣接する頂点が既に確定していた場合
        if (color[next_v] != -1) {
            if (color[next_v] == cur) { // 同色だった→二部グラフではない.
                return false;
            }

            // 色が既に確定しているのでスキップ
            continue;
        }

        // 隣接頂点の色を変えて、再帰的に探索
        // falseが返ってきたらfalseを返す
        if (!DFS(G, next_v, 1 - cur)) return false;
    }

    return true;
}


int main(int, char**) {

    // 超点数
    int N = 8;

    // グラフ
    Graph G(N);


    printf("無効グラフ\n");
    G[0].push_back(3); G[0].push_back(5); G[0].push_back(7);
    G[1].push_back(3); G[1].push_back(4); G[1].push_back(6);
    G[2].push_back(4); G[2].push_back(5); G[2].push_back(7);
    G[3].push_back(0); G[3].push_back(1); G[3].push_back(7);
    G[4].push_back(1); G[4].push_back(2); G[4].push_back(6);
    G[5].push_back(0); G[5].push_back(2);
    G[6].push_back(1); G[6].push_back(4); G[6].push_back(7);
    G[7].push_back(0); G[7].push_back(2); G[7].push_back(3); G[7].push_back(6);


    // 探索
    color.assign(N, -1);
    bool is_bipartite = true;
    for (int v = 0; v < N; ++v) {
        // vが探索済みの場合は探索しない
        if (color[v] != -1) continue;
        if (!DFS(G, v)) is_bipartite = false;
    }

    if (is_bipartite) cout << "Graphは二部グラフです\n";
    else cout << "Graphは二部グラフではありません\n"; 

}


    
