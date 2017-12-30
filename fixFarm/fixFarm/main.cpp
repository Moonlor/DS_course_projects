//
//  main.cpp
//  fixFarm
//
//  Created by 李坤 on 2017/11/1.
//  Copyright © 2017年 李坤. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    //建立优先队列，存储容器为vector<int>，最小值优先
    priority_queue<int, vector<int>, greater<int> > wood;
    int n;
    cin >> n;
    //将每段木材的长度读入优先队列中
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        wood.push(temp);
    }
    int count = 0;
    while (wood.size()!= 1) {
        //读出所需要木材长度中最短的两根
        int first = wood.top();
        wood.pop();
        int second = wood.top();
        wood.pop();
        //将这两根木材合并，作为一根新木材放入队列中，将两根木材的花销加入总花销内
        count += (first + second);
        wood.push(first + second);
    }
    cout << count << endl;
}



