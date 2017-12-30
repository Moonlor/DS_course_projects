#include <iostream>
#include "maze.h"
#include <stack>


stack<Point> way_out;       //保存当前所有可以前进的分支方向
stack<Point> temp_options;  //保存当前分支方向的出发点可以访问的路径点
stack<Point> right_path;    //保存当前经过验证可以通行的路径

//判断该点是否曾经过
bool blank(Point p, Maze * myMaze){
    if (myMaze->_sign[p.x][p.y] == 1){
        return false;
    }else{
        return true;
    }
}

//
void clear_way_options(void){
        while(!temp_options.empty()){
            temp_options.pop();
        }
};

//将某点周围可以走的路径点加入待判断栈内
void accessible(Point p, Maze * myMaze){
    for (int i = p.x - 1; i <= p.x + 1; ++i) {
        if(i < 0 || i >= myMaze->size()) continue;
        for (int j = p.y - 1; j <= p.y + 1; ++j) {
            if(j < 0 || j >= myMaze->size()) continue;  //超出地图
            if(!blank(Point(i, j), myMaze)) continue;   //已经经过
            if(myMaze->at(Point(i, j)) == '#') continue;//该点有围墙
            if(i == p.x - 1 && (j == p.y + 1 || j == p.y - 1)) continue;    //该点在四个角上
            if(i == p.x + 1 && (j == p.y + 1 || j == p.y - 1)) continue;    //该点在四个角上
            temp_options.push(Point(i, j));
        }
    }
}

bool adjacent(Point p1, Point p2){
    if(abs(p1.x - p2.x) + abs(p1.y - p2.y) == 1){
        return true;
    }
    return false;
}


int main() {
    Maze * myMaze = new Maze;
    myMaze->initialMaze();
    cout << endl;
    Point current = myMaze->_start_point;   //从起点出发
    way_out.push(current);                  //将起点加入路径
    myMaze->_sign[current.x][current.y] = 1;//标记已经经过起点
    while (1){
        //到达终点时，将最后一个经过的路径点加入栈内，然后退出循环
        if (way_out.top().equal(myMaze->_end_point)){
            Point next = way_out.top();
            right_path.push(next);
            break;
        }
        accessible(way_out.top(), myMaze);  //将某点周围可以走的路径点加入待判断栈内
        stack<Point> temp = temp_options;
        clear_way_options();                //清空待判断的路径点，等待下一次载入
        Point next = way_out.top();
        right_path.push(next);              //将上一次循环中得到的分叉口中的一个分支作为当前出发点

        //如果这条道路走到了死胡同
        if(temp.size() == 0){
            Point top = way_out.top();  //回溯上一个路径点
            way_out.pop();
            right_path.pop();
            while(adjacent(top, way_out.top())){
                //如果一条路的终点为死胡同，且在路径内没有分叉口，则将这条路的路径点全部退出，直到上一个分叉口
                top = way_out.top();
                way_out.pop();
                right_path.pop();
                if (way_out.empty()) {
                    cout << "没有正确通路，迷宫无解" << endl;
                    exit(0);
                }
            }
            continue;
        }

        while (temp.size() != 0){
            //将当前出发点的所有可能分支方向加入等待判断的路径点栈
            Point p = temp.top();
            temp.pop();
            way_out.push(p);
            myMaze->_sign[p.x][p.y] = 1;
        }
    }

    stack<Point> result;
    while(!right_path.empty()){
        Point tr = right_path.top();
        myMaze->_maze[tr.x][tr.y] = 'x';
        right_path.pop();
        result.push(tr);
    }

    myMaze->printMaze();
    cout << endl << endl << "迷宫路径： " << endl;
    while(!result.empty()){
        cout << '(' << result.top().x << ',' << result.top().y << ')';
        if (result.size() != 1){
            cout << " --> ";
        }
        result.pop();
    }
    cout << endl;

    return 0;
}
