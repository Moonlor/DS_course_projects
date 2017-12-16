//
//  main.cpp
//  BST
//
//  Created by 李坤 on 2017/11/6.
//  Copyright © 2017年 李坤. All rights reserved.
//

#include <iostream>
#include "Tree.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Tree *BST = nullptr;
    cout << "**          二叉排序树              \t**" << endl;
    cout << "=====================================" << endl;
    cout << "**        请选择要执行的操作:        \t**" << endl;
    cout << "**        1 --- 建立二叉排序树       \t**" << endl;
    cout << "**        2 --- 插入元素            \t**" << endl;
    cout << "**        3 --- 查询元素            \t**" << endl;
    cout << "**        4 --- 退出程序           \t**" << endl;
    cout << "=====================================" << endl;
    
    int instruct = 0;
    while (1) {
        cout << "请选择要执行的操作：" << endl;
        cin >> instruct;
        switch (instruct) {
            case 1:{
                getchar();
                BST = new Tree();
                if(BST == nullptr){
                    cerr << "内存分配错误" << endl;
                }
                cout << "二叉查找树如下所示：" <<endl;
                BST->show(BST->startPoint());
                break;
            }
            case 2:{
                if (BST == nullptr) {
                    cout << "二叉排序树还未建立，请先建立二叉排序树";
                    break;
                }
                cout << "请输入要插入的键值" <<endl;
                int temp;
                cin >> temp;
                BST->insert(temp);
                cout << "二叉查找树如下所示：" <<endl;
                BST->show(BST->startPoint());
                break;
            }
            case 3:{
                if (BST == nullptr) {
                    cout << "二叉排序树还未建立，请先建立二叉排序树";
                    break;
                }
                cout << "请输入要查找的键值" <<endl;
                int temp;
                cin >> temp;
                if(BST->find(temp, BST->startPoint()) == nullptr){
                    cout << "查询成功，该键值存在" << endl;
                }else{
                    cout << temp << "不存在" << endl;
                }
                break;
            }
            case 4:{
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
