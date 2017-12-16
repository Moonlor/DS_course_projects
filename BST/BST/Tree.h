//
//  Tree.h
//  BST
//
//  Created by 李坤 on 2017/11/6.
//  Copyright © 2017年 李坤. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include "Node.h"
#include <string>
#include <sstream>
using namespace std;

class Tree {
private:
    Node *_root;
public:
    Tree(){
        _root = nullptr;
        cout << "请输入构成二叉排序树的键值：" << endl;
        string in_string;
        stringstream stream;
        getline(cin, in_string);
        cout << in_string;
        stream << in_string;
        int temp = 0;
        cout << endl;
        while (stream >> temp) {
            insert(temp);
        }
    }
    
    void show(Node *current){
        if(current->getLeft() != nullptr){
            show(current->getLeft());
        }
        cout << current->value() << "->";
        if(current->getRight() != nullptr){
            show(current->getRight());
        }
    }
    
    Node *startPoint(void){
        return _root;
    }
    
    bool insert(int n){
        if(_root == nullptr){
            _root = new Node(n);
            if (_root == nullptr) {
                cerr << "内存分配错误" << endl;
                return false;
            }
        }else{
            Node *temp = find(n, _root);
            if (temp == nullptr) {
                cout << "输入的键值" << n << "已经存在" << endl;
            }else{
                Node *new_node = new Node(n);
                if (new_node == nullptr) {
                    cerr << "内存分配错误" << endl;
                    return false;
                }
//                if (temp->value() < n) {
//                    temp->addRight(new_node);
//                }else{
//                    temp->addLeft(new_node);
//                }
                temp->value() < n? temp->addRight(new_node) : temp->addLeft(new_node);
            }
        }
        
        return true;
    }
    
    Node *find(int n, Node *current){
        if (current->value() == n) {
            return nullptr;
        }else{
            if(current->value() < n){
                if (current->getRight() == nullptr) {
                    return current;
                }else{
                    return find(n, current->getRight());
                }
            }
            else{
                if (current->getLeft() == nullptr) {
                    return current;
                }else{
                    return find(n, current->getLeft());
                }
            }
        }
    }
    
};

#endif /* Tree_h */
