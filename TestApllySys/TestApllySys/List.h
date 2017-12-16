//
//  List.h
//  TestApllySys
//
//  Created by 李坤 on 2017/9/27.
//  Copyright © 2017年 李坤. All rights reserved.
//

#ifndef List_h
#define List_h

#include "InformationNode.h"
#include <string>
#include <iostream>

class List
{
protected:
    InformationNode * _start;
    InformationNode * _end;
    InformationNode * _init;
    int _totalNumber;
    
public:
    List()
    {
        _start = new InformationNode();
        _init = _start;
        _end = _start;
        _totalNumber = 0;
        
        _start->setAsEnd();
    }
    ~List(){
        InformationNode* current = _start;
        
        while(current->next() != nullptr){
            InformationNode* temp = current;
            current = current->next();
            delete temp;
        }
        
        delete current;
        
    }
    
    bool newNode();
    
    InformationNode * findStudent(int ex_id);
    InformationNode * insert(int position);
    InformationNode * modify(void);
    void deleteNode(int ex_id);
    void show(void);
    
    void printNode(InformationNode * target);
};

#endif /* List_h */






























