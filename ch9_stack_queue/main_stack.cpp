/**
 * @file main_stack.cpp
 * @author your name (you@domain.com)
 * @brief スタック
 * @version 0.1
 * @date 2021-10-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000; // スタック配列の最大サイズ

int st[MAX]; // スタックを表す配列
int top = 0; // スタックの先頭を表す添字

// スタックを初期化する
void init() {
    top = 0;
}

// スタックが空かどうかを判定する
bool isEmpty() {
    return (top == 0);
}

// スタックが満杯かどうかを判定する
bool isFull() {
    return (top == MAX);
}

// push
void push(int x) {
    if (isFull()) {
        cout << "error: stack is full." << endl;
        return;
    }
    st[top] = x;
    ++top;
}

// pos
int pop() {
    if (isEmpty()) {
        cout << "error: stack is empty." << endl;
        return -1;
    }
    --top;
    return st[top];
}


int main(int, char **) {

    init(); // {}

    push(3); // {} -> {3}
    push(5); // {3} -> {3,5}
    push(7); // {3,5} -> {3,5,7}

    cout << pop() << endl; // {3,5,7} -> {3,5}
    cout << pop() << endl; // {3,5} -> {3}

    push(9); // {3} -> {3,9}

    return 0;
}