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
    priority_queue<int, vector<int>, greater<int> > wood;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        wood.push(temp);
    }
    int count = 0;
    while (wood.size()!= 1) {
        int first = wood.top();
        wood.pop();
        int second = wood.top();
        wood.pop();
        count += (first + second);
        wood.push(first + second);
    }
    cout << count;
}
