/**
 * @file main_search_no_root_tree.cpp
 * @author your name (you@domain.com)
 * @brief 深さ優先探索による根なし木の走査
 * @version 0.1
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

/********************************/
/* 根なし木の走査の実装の基本形 */
/********************************/
// 根なし木上の探索
// v: 現在探索中の頂点, p: vの親(vが根のときはp=-1)
void dfs(const Graph& G, int v, int p = -1) {
    for (auto c : G[v]) {
        if (c == p) continue; // Point: 探索が親方向へ逆流するのを防ぐ

        // cはvの各子頂点を動く. このときcの親はvとなる.
        dfs(G, c, v);
    }
}

/******************************************************/
/* 根なし木を根付き木としたときの各頂点の深さを求める */
/******************************************************/
vector<int> depth; // 便宜上グローバルに答えを格納する
// d: 頂点vの深さ(vが根のときはd=0)
void dfs2(const Graph& G, int v, int p = -1, int d = 0) {
    // 深さの計算
    depth[v] = d;
    for (auto c : G[v]) {
        if (c == p) continue; // 探索が親方向へ逆流するのを防ぐ
        dfs2(G, c, v, d+1); // dを1つ増やして子頂点へ
    }
}


/***********************************************************************/
/* 根なし木を根付き木としたとき, 頂点vを根とした部分木のサイズを求める */
/***********************************************************************/
vector<int> subtree_size;
void dfs3(const Graph& G, int v, int p = -1, int d = 0) {
    // 深さ
    depth[v] = d; 

    for (auto c : G[v]) {
        if (c == p) continue;
        cout << "in-v: " << v << endl;
        dfs3(G, c, v, d+1);
    }

    cout << "out-v: " << v << endl;

    // 帰りがけ順で部分木のサイズを決める.
    subtree_size[v] = 1; // 自分自身
    for (auto c : G[v]) {
        if (c == p) continue;
        subtree_size[v] += subtree_size[c]; // 子頂点を根とする部分木のサイズを加算する
    }
}



int main(int, char**) {
    // 超点数
    int N = 15;

    // グラフ
    Graph G(N);

    printf("無効グラフ-サイクルなし\n");
    G[0].push_back(1); G[0].push_back(5); G[0].push_back(8);
    G[1].push_back(2); G[1].push_back(3);
    // G[2].push_back();
    G[3].push_back(4);
    // G[4].push_back();
    G[5].push_back(6); G[5].push_back(7);
    // G[6].push_back();
    // G[7].push_back();
    G[8].push_back(9); G[8].push_back(12);
    G[9].push_back(10); G[10].push_back(11);
    G[12].push_back(13); G[12].push_back(14);
    // G[13].push_back();
    // G[14].push_back();
    

    cout << "探索" << endl;
    // 探索
    int root = 0; // 仮に頂点0を根とする
    depth.assign(N, 0);
    subtree_size.assign(N, 0);

    cout << "開始" << endl;
    dfs3(G, root);


    // 結果
    for (int v = 0; v < N; ++v) {
        cout << v << ": depth = " << depth[v] << ", subtree_size = " << subtree_size[v] << endl;
    }
}
