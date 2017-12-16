//
//  MST.h
//  PowerGrid
//
//  Created by 李坤 on 2017/11/26.
//  Copyright © 2017年 李坤. All rights reserved.
//

#ifndef MST_h
#define MST_h

#define INFINITE INT_MAX

using namespace std;

//Minimum Spanning Tree
class MST{
private:
    int **_graph;
    char *_names;
    int* _index;
    int _n;
    int* _cost;
    int* _path;
    int _sum;
public:
    MST(){
        _graph = nullptr;
        _n = 0;
        _names = nullptr;
    }
    ~MST(){
        for (int i = 0; i < _n; i++) {
            delete [] _graph[i];
        }
        delete [] _graph;
        delete [] _names;
        delete [] _index;
        delete [] _cost;
        delete [] _path;
    }
    
    void createGraph(void){
        cout << "请输入顶点的个数：" << endl;
        cin >> _n;
        _graph = new int*[_n]();
        _names = new char[_n]();
        _index = new int[255]();
        _cost = new int[_n]();
        _path = new int[2 * (_n - 1)]();
        _sum = 0;
        memset(_index, -1, 255 * sizeof(int));
        cout << "请依次输入各顶点的名称：" << endl;
        for (int i = 0; i < _n; i++) {
            cin >> _names[i];
            _index[_names[i]] = i;
            _graph[i] = new int[_n]();
            for (int j = 0; j < _n; j++) {
                _graph[i][j] = INFINITE;
            }
        }
    }
    
    void addEdge(void){
        while (1) {
            cout << "请输入两个顶点及边：" << endl;
            char vertex_1, vertex_2;
            int weight;
            cin >> vertex_1 >> vertex_2 >> weight;
            if(vertex_1 == '?') {
                break;
            }
            _graph[_index[vertex_1]][_index[vertex_2]] = weight;
            _graph[_index[vertex_2]][_index[vertex_1]] = weight;
        }
    }
    
    void printGraph(void){
        for (int i = 0; i < _n; i++) {
            for (int j = 0; j < _n; j++) {
                cout << '\t' << _graph[i][j];
            }
            cout << endl;
        }
    }
    
    void generateMST(void){
        char start_vertex;
        cout << "请输入起始顶点：" << endl;
        cin >> start_vertex;
        if (_index[start_vertex] == -1) {
            cout << "该起始顶点不存在" << endl;
            return;
        }
        
        int *cost = new int[_n]();
        int *if_visited = new int[_n]();
        for (int i = 0; i < _n; i++) {
            cost[i] = _graph[_index[start_vertex]][i];
            _path[i] = _index[start_vertex];
            _cost[i] = _graph[_index[start_vertex]][i];
        }
        if_visited[_index[start_vertex]] = 1;
        
        int low_cost = INFINITE;
        int low_cost_index = 0;
        for (int i = 0; i < _n - 1; i++) {
            low_cost = INFINITE;
            for (int j = 0; j < _n; j++) {
                if(if_visited[j] != 1 && cost[j] < low_cost){
                    low_cost = cost[j];
                    low_cost_index = j;
                }
            }
            
            if_visited[low_cost_index] = 1;
            _sum += low_cost;
            
            for (int j = 0; j < _n; j++) {
                if (if_visited[j] != 1 && _graph[low_cost_index][j] < cost[j]) {
                    cost[j] = _graph[low_cost_index][j];
                    _path[j] = low_cost_index;
                    _cost[j] = cost[j];
                }
            }
        }
        delete [] if_visited;
    }
    
    void show(void)
    {
        cout << "最小生成树的顶点及边为：" << endl;
        for (int i = 0; i < _n; i++) {
            if(_cost[i] != INFINITE){
                cout << _names[i] << "-(" << _cost[i] << ")-" << _names[_path[i]] << endl;
            }
        }
    }
    
    
};


#endif /* MST_h */
