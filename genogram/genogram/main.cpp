//
//  main.cpp
//  genogram
//
//  Created by 李坤 on 2017/11/1.
//  Copyright © 2017年 李坤. All rights reserved.
//

#include <iostream>
#include "Tree.h"
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "**          家谱管理系统            \t**" << endl;
    cout << "======================================" << endl;
    cout << "**        请选择要执行的操作:        \t**" << endl;
    cout << "**        A --- 完善家谱           \t**" << endl;
    cout << "**        B --- 添加家庭成员        \t**" << endl;
    cout << "**        C --- 解散局部家庭        \t**" << endl;
    cout << "**        D --- 更改家庭成员姓名     \t**" << endl;
    cout << "**        E --- 退出程序           \t**" << endl;
    cout << "======================================" << endl;
    
    char instruct;
    Tree genogram;
    while (1) {
        cout << "请选择要执行的操作：" << endl;
        cin >> instruct;
        switch (instruct) {
            case 'A':{
                bool flag = genogram.newFamily();
                if(flag == false){
                    cerr << "操作执行失败" << endl;
                }
                break;
            }
            case 'B':{
                bool flag = genogram.addNewMember();
                if(flag == false){
                    cerr << "操作执行失败" << endl;
                }
                break;
            }
            case 'C':{
                genogram.dissolveFamily();
                break;
            }
            case 'D':{
                genogram.changeName();
                break;
            }
            case 'E':{
                cout << "感谢您使用本系统，祝您心明眼亮，再见！" << endl;
                return 0;
            }
            default:
                cout << "错误输入" << endl;
                break;
        }
    }
    
    return 0;
}
