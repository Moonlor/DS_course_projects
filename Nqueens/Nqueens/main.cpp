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
    if (layer == n) {
        printResult(q, n);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == 0 && l[layer + i] == 0 && r[n + i - layer] == 0) {
            q[layer] = i;
            l[layer + i] = 1;
            v[i] = 1;
            r[n + i - layer] = 1;
            recall(layer+1, n, q, v, l, r);
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
    cout << "皇后摆法: " << endl;
    int* q = new int[n]();
    int* v = new int[n]();
    int* l = new int[2 * n]();
    int* r = new int[2 * n]();
    
    recall(0, n, q, v, l, r);
    
    cout << "共有" << total_count << "种解法!" << endl;
    
    return 0;
}





