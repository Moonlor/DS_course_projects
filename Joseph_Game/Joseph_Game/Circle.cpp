//
//  Circle.cpp
//  Joseph_Game
//
//  Created by 李坤 on 2017/10/25.
//  Copyright © 2017年 李坤. All rights reserved.
//

#include <iostream>
#include "Node.h"

using namespace std;

class Circle{
private:
    int _total_person;
    int _gap;
    Node * _first_node;
    int _start_position;
    int _survive_number;
public:
    Circle(){
        _total_person = 0;
        _gap = 0;
        _first_node = nullptr;
        
        cout << "请输入生死游戏的总人数N: " << endl;
        cin >> _total_person;
        cout << "请输入游戏开始的位置S: " << endl;
        cin >> _start_position;
        cout << "请输入死亡数字M: " << endl;
        cin >> _gap;
        cout << "请输入剩余的剩者人数K: " << endl;
        cin >> _survive_number;
        
        int n = _total_person;
        Node * last_node = nullptr;
        int count = 0;
        while(n!= 0){
            Node * temp = new Node(count + 1);
            count++;
            
            if(_first_node == nullptr){
                _first_node = temp;
            }
            
            if(last_node == nullptr){
                last_node = temp;
            }
            
            last_node->setNext(temp);
            temp->setNext(_first_node);
            
            last_node = temp;
            n--;
        }
    }
    
    ~Circle(){
        int n = _total_person;
        Node * current_node = _first_node;
        while (_total_person != 0) {
            _total_person--;
            Node * temp = current_node;
            current_node = current_node->nextNode();
            delete (temp);
        }
    }
    
    void kill(void)
    {
        int count = _total_person - _survive_number;
        Node * current_node = _first_node;
        
        while(count != 0){
            count --;
            int loop = _gap;
            while(loop != 0){
                loop--;
                current_node = current_node->nextNode();
            }
            current_node->killThisOne(count);
        }
        
    }
    
    void showResult(void){
        int n = _total_person;
        Node * current_node = _first_node;
        cout << "最后剩下" << _survive_number << "人" << endl;
        cout << "剩余的生者位置为：";
        while (n != 0) {
            n--;
            if(current_node->isAlive() == true){
                cout << current_node->getNumber() << '\t';
            }
        }
    }
    
    
};
