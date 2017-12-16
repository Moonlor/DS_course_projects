//
//  main.cpp
//  TestApllySys
//
//  Created by 李坤 on 2017/9/27.
//  Copyright © 2017年 李坤. All rights reserved.
//

#include "InformationNode.h"
#include "List.h"

using namespace std;

int main(void)
{
    cout << "首先请建立考生信息系统" << endl;
    List system;
    cout << "请输入考生人数" << endl;
    int num;
    cin >> num;
    if (num != 0) cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别！" << endl;
    while(num != 0){
        num--;
        system.newNode();
    }
    
    while(1){
        cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消" << endl;
        int operator_num = 0;
        cin >> operator_num;
        switch (operator_num) {
            case 1:{
                cout << "请输入你要插入的考生的位置:" << endl;
                int pos;
                cin >> pos;
                system.insert(pos);
                break;
            }
            case 2:{
                cout << "请输入你要删除的考生的考号:" << endl;
                int id;
                cin >> id;

                system.deleteNode(id);
                break;
            }
            case 3:{
                cout << "请输入你要查找的考生的考号:" << endl;
                int id;
                cin >> id;
                InformationNode *target = system.findStudent(id);
                if (target == nullptr) {
                    cout << "该考生不存在！" << endl;
                    continue;
                }
                cout << "你查找的考生信息为：";
                system.printNode(target);
                break;
            }
            case 4:{
                system.modify();
                break;
            }
            case 5:{
                system.show();
                break;
            }
            case 0:{
                cout << "感谢您的使用，祝您心明眼亮，再见！" << endl;
                return 0;
            }
            default:{
                cout << "命令不存在! " << endl;
                break;
            }
        }
        
    }
    
    return 0;
}
