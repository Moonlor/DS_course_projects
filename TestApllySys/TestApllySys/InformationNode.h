//
//  InformationNode.h
//  TestApllySys
//
//  Created by 李坤 on 2017/9/27.
//  Copyright © 2017年 李坤. All rights reserved.
//

#ifndef InformationNode_h
#define InformationNode_h

#include <iostream>
#include <string>

using namespace std;

class InformationNode
{
protected:
    int _examId;
    int _age;
    
    string _name;
    string _gender;
    string _examSubject;
    
    InformationNode * _next;
    
public:
    InformationNode()
    {
        _examId = 0;
        _name = "NULL";
        _gender = "无";
        _age = 999;
        _examSubject = "无";
    }
    
    InformationNode(int examId, int age, string name = "NULL", string gender = "无", string examSubject = "无")
    {
        _examId = examId;
        _age = age;
        _name = name;
        _gender = gender;
        _examSubject = examSubject;
    }
    
    InformationNode * next(){
        return _next;
    }
    
    void setAsEnd(){
        _next = nullptr;
    }
    
    void changeNext( InformationNode* ptr){
        _next = ptr;
    }
    
    string getName(){
        return _name;
    }
    
    void changeName(string name){
        _name = name;
    }
    
    string getGender(){
        return _gender;
    }
    
    void changeGender(string gender){
        _gender = gender;
    }
    
    string getExamSubject(){
        return _examSubject;
    }
    
    void changeExamSubject(string subject){
        _examSubject = subject;
    }
    
    int getExamId(){
        return _examId;
    }
    
    void changeExamId(int id){
        _examId = id;
    }
    
    int getAge(){
        return _age;
    }
    
    void changeAge(int age){
        _age = age;
    }
};

#endif /* InformationNode_h */
