//
//  Node.h
//  Joseph_Game
//
//  Created by 李坤 on 2017/10/25.
//  Copyright © 2017年 李坤. All rights reserved.
//

#ifndef Node_h
#define Node_h

using namespace std;

class Node{
private:
    int _number;
    Node * _next;
    bool _survive;
public:
    Node(int n){
        _number = n;
        _next = nullptr;
        _survive = true;
    }
    
    int getNumber(void){
        return _number;
    }
    
    void setNumber(int new_number){
        _number = new_number;
    }
    
    void setNext(Node * next){
        _next = next;
    }
    
    void killThisOne(int n){
        _survive = false;
        cout << "第" << n << "个死者的位置是" << _number << endl;
    }
    
    bool isAlive(void){
        return _survive;
    }
    
    Node *nextNode(void){
        return _next;
    }
};

#endif /* Node_h */
