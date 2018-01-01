//
//  main.cpp
//  strMatching
//
//  Created by 李坤 on 2017/10/31.
//  Copyright © 2017年 李坤. All rights reserved.
//

#include<iostream>
#include<string>
#include <vector>
#include <fstream>

using namespace std;

int _locate[256];       //辅助数组，用于统计单词中字母出现的位置，如果有两个相同字母，则记录最后一个字母出现的位置
int _total_count = 0;   //某单词出现的总次数

void locate_next_char(string pattern){
    int m = pattern.size();
    for (int i = 0; i < 256; i++) {
        _locate[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        _locate[pattern[i]] = i;    //以第i个字符为索引，指向目标字符串中第i个字符最后出现的位置
    }
}

int search(string pattern, string target, int mode, int row)
{
    //mode = 1,仅统计单词出现的次数，mode = 2，输出单词所在行号，出现次数以及相应位置
    int m = pattern.size();
    int n = target.size();
    locate_next_char(pattern);
    
    for (int i = 0; i < n - m + 1; ) {
        //i为主串中指向当前判定字符的索引
        //j为一次判定流程中指向已正确匹配的字符串末尾的索引
        int j = i;
        int k = 0;
        
        for (; k < m && j < n && pattern[k] == target[j]; k++, j++) ;
        
        if (k == m) {
            //匹配成功
            if (mode == 1) {
                _total_count ++;
            }
            if(mode == 2){
                cout << "单词 " << pattern << " 出现在第" << row << "行 第" << i << "位置"<< endl;
            }
            //如果匹配结束后仍然未达到该行的末尾
            if(i + m < n){
                //索引向后移动直至目标字符串中下一个查找的字符与模式串中出现的最后一个相同字符对齐
                //如果模式串中未出现相同字符，则将索引直接后移模式串长度+1
                i += m - _locate[target[i + m]];
            }else{
                return -1;
            }
        }else{
            //如果匹配失败
            //索引向后移动直至目标字符串中下一个查找的字符与模式串中出现的最后一个相同字符对齐
            //如果模式串中未出现相同字符，则将索引直接后移模式串长度+1
            if(i + m < n){
                i += m - _locate[target[i + m]];
            }else{
                return -1;
            }
        }
    }
    
    return -1;
}


int main()
{
    cout << "请输入文本文件路径: " << endl;
    string route;
    cin >> route;
    vector<string> text;
    
    ifstream in(route);
    if (! in.is_open()){
        cerr << "打开文本文件失败" << endl;
        exit (0);
    }
    char buffer[256];
    while (!in.eof()) {
        string temp;
        in.getline(buffer, 256);
        temp = buffer;
        text.push_back(temp);
    }
    
    while (1) {
        cout << "请输入要查询的单词，输入  quit_  结束查询: " << endl;
        _total_count = 0;
        string pattern;
        cin >> pattern;
        if(pattern == "quit_"){
            cout << "感谢您的使用，祝您心明眼亮，再见！" << endl;
            break;
        }
        for (int i = 0; i < text.size(); i++){
            search(pattern, text[i], 1, i);
        }
        cout << "单词 " << pattern << " 一共出现了" << _total_count << "次" << endl;
        if(_total_count == 0) continue;
        for (int i = 0; i < text.size(); i++){
            search(pattern, text[i], 2, i);
        }
    }
    in.close();
    return 0;
}
