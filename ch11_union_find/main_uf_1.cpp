/**
 * @file main_uf_1.cpp
 * @author your name (you@domain.com)
 * @brief Union Find
 * @version 0.1
 * @date 2021-10-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

/*

// 経路圧縮を用いない場合のroot関数
// 各頂点xに対して, 親をpar[x]とする. xが親の場合par[x] = -1
// 再帰関数で実装できる
int root(int x) {
    if (par[x] == -1) return x; // 親が根の場合はxを直接返す.
    else return root(par[x]); // xが根でないなら再帰的に親へと進む
}


// 経路圧縮 = 頂点xの親par[x]をxが所属する根root(x)にすげ替える
int root(int x) {
    if (par[x] == -1) return x;
    else return par[x] = root(par[x]); // xの親par[x]を根にすげ替える
}

*/


// Union-Find構造体
struct UnionFind 
{
    vector<int> par, siz;

    // 初期化
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
    UnionFind uf(7); // {0}, {1}, {2}, {3}, {4}, {5}, {6}

    uf.unite(1, 2); // {0}, {1, 2}, {3}, {4}, {5}, {6}
    uf.unite(2, 3); // {0}, {1, 2, 3}, {4}, {5}, {6}
    uf.unite(5, 6); // {0}, {1, 2, 3}, {4}, {5, 6}
    cout << boolalpha << uf.issame(1, 3) << endl;
    cout << boolalpha << uf.issame(2, 5) << endl;

    uf.unite(1, 6); // {0}, {1, 2, 3, 5, 6}, {4}
    cout << boolalpha << uf.issame(2, 5) << endl;
}
