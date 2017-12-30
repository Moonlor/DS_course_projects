//
//  Tree.h
//  genogram
//
//  Created by 李坤 on 2017/11/1.
//  Copyright © 2017年 李坤. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include<vector>

using namespace std;

class Node
{
public:
    string _name;
    Node * _elder;
    vector<Node*> _offspring;
    
    Node(string name, Node * elder_generation){
        _name = name;
        _elder = elder_generation;
    }
};

class Tree
{
private:
    int _total_number;
    Node * _ancestor;
public:
    Tree(void){
        cout << "首先建立一个家谱！" << endl << "请输入祖先的姓名: ";
        string name;
        cin >> name;
        _ancestor = new Node(name, nullptr);
        if(checkOk(_ancestor)){
            cout << "此家谱的祖先是：" << _ancestor->_name << endl;
        }
    }
    ~Tree(void){
        dissolve(_ancestor, 2);
    }
    
    //查看每次为家谱成员分配内存空间是否成功
    bool checkOk(void* object){
        if (object == nullptr) {
            cerr << "内存分配出错" << endl;
            return false;
        }
        return true;
    }
    
    //根据名字查找某位家谱成员
    Node * find(string name, Node * current){
        Node *target = nullptr;
        if(current->_name == name){
            return current;
        }else{
            for (int i = 0; i < current->_offspring.size(); i++) {
                target = find(name, current->_offspring[i]);
                if(target == nullptr) continue;
                if(target->_name == name){
                    return target;
                }
            }
        }
        return target;
    }
    
    //打印某位家谱成员的所有子代
    void printChild(Node *parent){
        if (parent == nullptr) {
            return;
        }
        cout << parent->_name << "的第一代子孙是: ";
        for (int i = 0; i < parent->_offspring.size(); i++) {
            cout << parent->_offspring.at(i)->_name << " ";
        }
        cout << endl;
    }
    
    //解散某个家庭
    void dissolve(Node *parent, int mode){
        // mode1: 仅解散子女，mode2: 删除自己、子女
        Node *link = parent;
        if(parent->_offspring.size() == 0 && mode == 2){
            delete parent;
            return;
        }
        
        for (int i = 0; i < link->_offspring.size(); i++) {
            dissolve(link->_offspring.at(i), 2);
        }
        link->_offspring.clear();
    }
    
    //添加新的家庭成员
    bool addNewMember(void){
        cout << "请输入要添加儿子（或）女儿的人的姓名：" << endl;
        string name;
        cin >> name;
        Node * parent = find(name, _ancestor);
        if (parent == nullptr) {
            cout << "此人不存在～" << endl;
            return false;
        }
        cout << "请输入" << parent->_name <<"新添加的儿子（或女儿）的姓名: " << endl;
        string child_name;
        cin >> child_name;
        Node * _child = new Node(child_name, parent);
        if(checkOk(_child)){
            parent->_offspring.push_back(_child);
        }
        printChild(parent);
        return true;
    }
    
    //建立新的家庭
    bool newFamily(void){
        cout << "请输入要建立家庭的人的姓名：" << endl;
        string name;
        cin >> name;
        Node *parent = find(name, _ancestor);
        if (parent == nullptr) {
            cout << "此人不存在～" << endl;
            return false;
        }
        cout << "请输入" << parent->_name << "的儿女人数: " << endl;
        int number;
        cin >> number;
        if(number <= 0) {cerr << "非法输入" << endl; return false;}
        cout << "请依次输入" << parent->_name <<"的儿女的姓名: " << endl;
        vector<string> name_list;
        for (int i = 0; i < number; i++) {
            string temp;
            cin >> temp;
            name_list.push_back(temp);
        }
        for (int i = 0; i < number; i++) {
            Node * _child = new Node(name_list[i], parent);
            if(checkOk(_child)){
                parent->_offspring.push_back(_child);
            }
        }
        printChild(parent);
        return true;
    }
    
    //解散某个家庭
    void dissolveFamily(void){
        cout << "请输入要解散家庭的人的姓名：" ;
        string name;
        cin >> name;
        Node *parent = find(name, _ancestor);
        if (parent == nullptr) {
            cout << "此人不存在～" << endl;
            return ;
        }
        printChild(parent);
        dissolve(parent, 1);
    }
    
    //更改某位家庭成员的姓名
    void changeName(void){
        cout << "请输入要更改姓名的人的目前姓名：" << endl;
        string name;
        cin >> name;
        Node *parent = find(name, _ancestor);
        if (parent == nullptr) {
            cout << "此人不存在～" << endl;
            return ;
        }
        cout << "请输入更改后的姓名：" ;
        string new_name;
        cin >> new_name;
        parent->_name = new_name;
        cout << name << "已更名为" << new_name << endl;
    }
};

#endif /* Tree_h */
