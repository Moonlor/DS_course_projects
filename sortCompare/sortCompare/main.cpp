//
//  main.cpp
//  sortCompare
//
//  Created by 李坤 on 2017/11/7.
//  Copyright © 2017年 李坤. All rights reserved.
//

#include <iostream>
using namespace std;

#include "sort.h"

bool check(int total, int* target){
    for (int i = 0; i < total - 1; i++) {
        if(target[i] > target[i + 1]){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout << "**          排序算法比较            \t**" << endl;
    cout << "=====================================" << endl;
    cout << "**        1 --- 冒泡排序           \t**" << endl;
    cout << "**        2 --- 选择排序           \t**" << endl;
    cout << "**        3 --- 直接插入排序        \t**" << endl;
    cout << "**        4 --- 希尔排序           \t**" << endl;
    cout << "**        5 --- 快速排序           \t**" << endl;
    cout << "**        6 --- 堆排序             \t**" << endl;
    cout << "**        7 --- 归并排序           \t**" << endl;
    cout << "**        8 --- 基数排序           \t**" << endl;
    cout << "**        9 --- 退出程序           \t**" << endl;
    cout << "=====================================" << endl;
    
    cout << "请输入要产生的随机数的个数：" << endl;
    int n;
    cin >> n;
    int* random_num = new int[n]();
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        random_num[i] = rand();
    }
    
    int instruct = 0;
    while (1) {
        cout << "请选择排序算法" <<endl;
        cin >> instruct;
        switch (instruct) {
            case 1:{
                BubbleSort* bs = new BubbleSort();
                int *bs_result = bs->sort(random_num, n);
                if (check(n, bs_result)) {
                    cout << "correct" << endl;
                }
                break;
            }
            case 2:{
                SelectionSort* ss = new SelectionSort();
                int *ss_result = ss->sort(random_num, n);
                if (check(n, ss_result)) {
                    cout << "correct" << endl;
                }
                break;
            }
            case 3:{
                DirectionInsertionSort* dis = new DirectionInsertionSort();
                int *dis_result = dis->sort(random_num, n);
                if (check(n, dis_result)) {
                    cout << "correct" << endl;
                }
                break;
            }
            case 4:{
                ShellSort* ss = new ShellSort();
                int *ss_result = ss->sort(random_num, n);
                if (check(n, ss_result)) {
                    cout << "correct" << endl;
                }
                break;
            }
            case 5:{
                QuickSort* qs = new QuickSort();
                int *qs_result = qs->sort(random_num, n);
                if (check(n, qs_result)) {
                    cout << "correct" << endl;
                }
                break;
            }
            case 6:{
                HeapSort* hs = new HeapSort();
                int *hs_result = hs->sort(random_num, n);
                if (check(n, hs_result)) {
                    cout << "correct" << endl;
                }
                break;
            }
            case 7:{
                MergeSort* ms = new MergeSort();
                int *ms_result = ms->sort(random_num, n);
                if (check(n, ms_result)) {
                    cout << "correct" << endl;
                }
                break;
            }
            case 8:{
                RadixSort* rs = new RadixSort();
                int *rs_result = rs->sort(random_num, n);
                if (check(n, rs_result)) {
                    cout << "correct" << endl;
                }
                break;
            }
            case 9:{
                cout << "感谢您使用本系统，祝您心明眼亮，再见！" << endl;
                return 0;
            }
            default:
                cout << "错误输入";
                break;
        }
    }
    return 0;
}
