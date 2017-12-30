//
//  main.cpp
//  Nqueens
//
//  Created by 李坤 on 2017/10/25.
//  Copyright © 2017年 李坤. All rights reserved.
//

#include <iostream>

using namespace std;

int total_count = 0;

//打印满足条件的N皇后的位置
void printResult(int * queen, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == queen[i]) {
                cout << "x ";
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
    total_count++;
}

void recall(int layer, int n, int * q, int * v, int * l, int * r)
{
    //当找到第n+1行时，表面前n个皇后已经填入n行中，得到一个解并打印
    if (layer == n) {
        printResult(q, n);
        return;
    }
    for (int i = 0; i < n; i++) {
        //判断第layer行第i个位置在列、左斜线、右斜线三个方向是否合法
        if (v[i] == 0 && l[layer + i] == 0 && r[n + i - layer] == 0) {
            q[layer] = i;
            l[layer + i] = 1;
            v[i] = 1;
            r[n + i - layer] = 1;
            //在该行放下一个皇后之后，递归调用寻找下一个皇后的位置
            recall(layer+1, n, q, v, l, r);
            //回溯，抹掉之前的改变
            q[layer] = 0;
            v[i] = 0;
            l[layer + i] = 0;
            r[n + i - layer] = 0;
        }
    }
}
int main(int argc, const char * argv[]) {
    cout << "现有N * N的棋盘，放入N个皇后，要求所有皇后不在同一行、列和同一斜线上！" << endl;
    cout << "请输入皇后的个数" << endl;
    int n = 0;
    cin >> n;
    if(n <= 0){
        cerr << "输入非法！" << endl;
        exit(0);
    }
    cout << "皇后摆法: " << endl;
    int* q = new int[n]();      //第n个皇后所在的列坐标
    int* v = new int[n]();      //辅助数组，用来标记第i列是否有已经有皇后占用
    int* l = new int[2 * n]();  //辅助数组，用来标记第i条左斜线是否已经有皇后占用
    int* r = new int[2 * n]();  //辅助数组，用来标记第i条右斜线是否已经有皇后占用
    
    recall(0, n, q, v, l, r);
    
    cout << "共有" << total_count << "种解法!" << endl;
    
    return 0;
}





