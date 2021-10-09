/**
 * @file main_ds_list.cpp
 * @author your name (you@domain.com)
 * @brief データ構造 連結リスト
 * @version 0.1
 * @date 2021-10-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <vector>
#include <iostream>
#include <string>
using namespace std;


// 自己参照構造体
struct Node 
{
    Node *prev;
    Node *next; // 次がどのノードを指すか
    string name; // ノードに付随している値

    Node(string name_ = "") : prev(nullptr), next(nullptr), name(name_) {}
};


// 番兵を表すノードをグローバル領域に置いておく
Node *nil;

// 初期化
void init() 
{
    nil = new Node();
    nil->prev = nil;
    nil->next = nil; // 初期状態ではnilがnilを指すようにする
}

// 連結リストを出力する
void printList() 
{
    Node* cur = nil->next; // 先頭から出発
    for (; cur != nil; cur = cur->next) {
        cout << cur->name << " -> ";
    }
    cout << endl;
}

// ノードpの直後にノードvを挿入する
// ノードpのデフォルト引数をnilとしておく
// そのためinsert(v)を呼び出す操作は、リストの先頭への挿入を表す
void insert(Node* v, Node* p = nil) 
{
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

// ノードvを削除する
void erase(Node *v) {
    if (v == nil) return; // vが番兵の場合何もしない
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v; // メモリ解放
}




int main(int, char**) 
{
    // 単方向リスト
    // {
    //     // 初期化
    //     init();

    //     // 作りたいノードの名前の一覧
    //     // 最後尾のノード（山本）から順に挿入することに注意
    //     vector<string> names = {
    //         "Yamamoto",
    //         "Watanabe",
    //         "Ito",
    //         "Takahashi",
    //         "Suzuki",
    //         "Sato"
    //     };

    //     // 各ノードを生成して、連結リストの先頭に挿入していく
    //     for (int i = 0; i < (int)names.size(); ++i)
    //     {
    //         // ノードを生成する
    //         Node* node = new Node(names[i]);

    //         // 生成したノードを連結リストの先頭に挿入する
    //         insert(node);

    //         // 各ステップの連結リストの様子を出力
    //         cout << "step " << i << ": ";
    //         printList();
    //     }
    // }
    
    // 双方向リスト
    {
        // 初期化
        init();

        // ノード
        vector<string> names = {
            "Yamamoto",
            "Watanabe",
            "Ito",
            "Takahashi",
            "Suzuki",
            "Sato"
        };

        // 連結リスト作成：　各ノードを生成して連結リストの先頭に挿入していく
        Node *watanabe;
        for (int i = 0; i < (int)names.size(); ++i)
        {
            // ノード生成
            Node *node = new Node(names[i]);

            // 作成したノードを連結リストに挿入
            insert(node);

            // 『渡辺』ノードを保持しておく
            if (names[i] == "Watanabe") watanabe = node;
        }

        // 渡辺ノードを削除する
        cout << "before: "; printList();
        erase(watanabe);
        cout << "aflter: "; printList();
    }

}