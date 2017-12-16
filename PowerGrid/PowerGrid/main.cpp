//
//  main.cpp
//  PowerGrid
//
//  Created by 李坤 on 2017/11/22.
//  Copyright © 2017年 李坤. All rights reserved.
//

#include <iostream>
#include "MST.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "**          电网造价模拟系统        \t**" << endl;
    cout << "=====================================" << endl;
    cout << "**        A --- 创建电网顶点       \t**" << endl;
    cout << "**        B --- 添加电网的边       \t**" << endl;
    cout << "**        C --- 构造最小生成树      \t**" << endl;
    cout << "**        D --- 显示最小生成树      \t**" << endl;
    cout << "**        E --- 退出程序           \t**" << endl;
    cout << "=====================================" << endl;
    
    char instruct;
    MST *grid = new MST();
    while (1) {
        cout << "请选择操作：" <<endl;
        cin >> instruct;
        switch (instruct) {
            case 'A':{
                grid->createGraph();
                break;
            }
            case 'B':{
                grid->addEdge();
                break;
            }
            case 'C':{
                grid->generateMST();
                break;
            }
            case 'D':{
                grid->show();
                break;
            }
            case 'E':{
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
