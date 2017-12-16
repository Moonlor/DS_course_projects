//
//  List.cpp
//  TestApllySys
//
//  Created by 李坤 on 2017/10/11.
//  Copyright © 2017年 李坤. All rights reserved.
//

#include <iostream>
#include "List.h"

using namespace std;

bool List::newNode()
{
    int student_id;
    int student_age;
    string name;
    string gender;
    string exam_subject;
    
    std::cin >> student_id >> name >> gender >> student_age >> exam_subject;
    
    InformationNode * temp = new InformationNode(student_id, student_age, name, gender, exam_subject);
    
    if(temp == nullptr){
        cerr << "Memory allocate Error!";
        return false;
    }
        
    _end->changeNext(temp);
    _end = temp;
    _end->setAsEnd();
        
    if(_start == _init){
        _start->changeNext(temp);
        _start = temp;
    }
    
    _totalNumber++;

    return true;
}

InformationNode * List::findStudent(int ex_id)
{
    InformationNode *current = _start;
    
    if(_start == _init){
        cerr << "系统为空 !!!" << endl;
        return nullptr;
    }
    
    while (current->next() != nullptr) {
        if(current->getExamId() == ex_id){
            return current;
        }else{
            current = current->next();
        }
    }
    
    if(current->getExamId() == ex_id){
        return current;
    }else{
        current = current->next();
    }
    
    return nullptr;
}

InformationNode * List::insert(int position)
{
    if(position > _totalNumber + 1){
        cerr << "插入位置不合法，请重新选择操作！" << endl;
        return nullptr;
    }
    
    std::cout << "请依次输入你要插入的考生的考号，姓名，性别，年龄及报考类别！" << endl;
    string name, gender, subject;
    int id, age;
    cin >> id >> name >> gender >> age >> subject;
    
    InformationNode * temp = new InformationNode(id, age, name, gender, subject);
    
    if(temp == nullptr){
        cerr << "内存分配错误" << endl;
        return nullptr;
    }
    
    InformationNode *current = _start;
    InformationNode * before = nullptr;
    
    int count = 1;
    
    while (count != position) {
        count ++;
        before = current;
        current = current->next();
    }
    
    if(current == nullptr){
        _end->changeNext(temp);
        _end = temp;
        _end->setAsEnd();
    }else if(before == nullptr){
        if(_totalNumber == 0){
            _end->changeNext(temp);
            _end = temp;
            _end->setAsEnd();
            _start->changeNext(temp);
            _start = temp;
        }else{
            temp->changeNext(_start);
            _start = temp;
        }
    }else{
        before->changeNext(temp);
        temp->changeNext(current);
    }
    
    _totalNumber++;
    this->show();
    return temp;
}

InformationNode * List::modify(void)
{
    cout << "请输入你要修改的考生的考号" << endl;
    int id;
    cin >> id;
    
    InformationNode* target = this->findStudent(id);
    if(target == nullptr){
        cerr << "此学生并不存在" << endl;
        return nullptr;
    }
    
    std::cout << "请依次输入你要修改的考生的考号、姓名，性别，年龄及报考类别！" << endl;
    string name, gender, subject;
    int age,new_id;
    cin >> new_id >> name >> gender >> age >> subject;
    
    target->changeExamId(new_id);
    target->changeName(name);
    target->changeGender(gender);
    target->changeAge(age);
    target->changeExamSubject(subject);
    
    return target;
}

void List::show()
{
    if(_start == _init){
        cerr << "系统中不存在任何考生信息" << endl;
        return;
    }
    
    InformationNode * current = _start;
    cout << "考号"<< '\t'<< "姓名" << "\t\t"<< "性别" << '\t' << "年龄" << '\t' << "报考类别" << endl;
    
    while (current->next() != nullptr) {
        printNode(current);
        current = current ->next();
    }
    printNode(current);
}

void List::printNode(InformationNode * target)
{
    if(target == nullptr){
        cerr << "统计出错，此生信息不存在" << endl;
        return;
    }
    
    cout << target->getExamId() << '\t'<< target->getName() << '\t'<< target->getGender() << '\t' << target->getAge() << '\t' << target->getExamSubject() << endl;
    
}

void List::deleteNode(int ex_id)
{
    InformationNode* target = this->findStudent(ex_id);
    if(target == nullptr){
        cerr << "此学生并不存在" << endl;
        return;
    }
    
    InformationNode *current = _start;
    
    if(_start == _init){
        cerr << "系统为空，不存在任何学生" << endl;
        return;
    }
    
    if(target == _start){
        if(_start == _end){
            delete target;
            _totalNumber--;
            _start = _init;
            _end = _init;
            return;
        }
        else{
            _start = target->next();
            delete target;
            _totalNumber--;
            return;
        }
    }
    
    while (current->next() != target) {
        current = current->next();
    }
    
    if(target == _end){
        current->setAsEnd();
    }else{
        current->changeNext(target->next());
    }
    cout << "你删除的考生信息是：";
    printNode(target);
    cout << endl;
    delete target;
    _totalNumber--;
    this->show();
}



