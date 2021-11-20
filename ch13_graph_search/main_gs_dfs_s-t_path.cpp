/**
 * @file main_gs_dfs_s-t_path.cpp
 * @author your name (you@domain.com)
 * @brief 深さ優先探索によるs-tパスの存在チェック.
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

// 深さ優先探索
vector<bool> seen;
void DFS(const Graph& G, int v) {
    seen[v] = true; // vを訪問済みにする

    // vから行ける各頂点next_vについて
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_vが探索済みなら探索しない
        DFS(G, next_v); // 再帰的に探索
    }
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

    seen.assign(N, false); // 全頂点を「未訪問」に初期化

    int sv;
    printf("始点s: "); cin >> sv; // 始点: s

    // 深さ優先探索
    DFS(G, sv);

    int tv;
    printf("s-tパスのt: "); cin >> tv; // t
    if (tv > 7) {
        printf("無効です\n");
        return 0;
    }

    if (seen[tv]) cout << "s-tパスは存在します\n";
    else cout << "s-tパスは存在しません\n";

}