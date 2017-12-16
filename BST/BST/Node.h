//
//  Node.h
//  BST
//
//  Created by 李坤 on 2017/11/6.
//  Copyright © 2017年 李坤. All rights reserved.
//

#ifndef Node_h
#define Node_h

class Node {
private:
    Node* _left;
    Node* _right;
    int _number;
public:
    Node(int n = -1)
    {
        _number = n;
        _left = nullptr;
        _right = nullptr;
    }
    
    void addLeft(Node* t){
        _left = t;
    }
    
    void addRight(Node* t){
        _right  = t;
    }
    
    Node* getLeft(void){
        return _left;
    }
    
    Node* getRight(void){
        return _right;
    }
    
    int value(void){
        return _number;
    }
};

#endif /* Node_h */
