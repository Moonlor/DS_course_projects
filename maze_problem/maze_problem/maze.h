//
// Created by 李坤 on 2017/10/31.
//

#ifndef MAZE_MAZE_H
#define MAZE_MAZE_H

using namespace std;

class Point{
public:
    int x;
    int y;

    Point(int _x = 0, int _y = 0){
        x = _x;
        y = _y;
    }

    //判定两点是否相等
    bool equal(Point in){
        return (this->x == in.x) && (this->y == in.y);
    }
};

class Maze
{
private:
    int _size;              //迷宫大小
public:
    Point _start_point;     //迷宫起点
    Point _end_point;       //迷宫终点
    char **_maze;           //指向迷宫的指针
    int **_sign;            //判断是否曾经过该点
    Maze(){
        _size = 7;
        _maze = new char *[_size];
        for (int i = 0; i < _size; ++i) {
            _maze[i] = new char [_size];
        }
        _sign = new int *[_size];
        for (int i = 0; i < _size; ++i) {
            _sign[i] = new int [_size]();
        }
    }

    ~Maze(){
        for (int i = 0; i < _size; ++i) {
            delete[] _maze[i] ;
        }
        delete[] _maze;
    }

    int initialMaze(void){

        int instruct = 1;
        cout << "请输入指令来选择输入地图或使用内置地图" << endl;
        cout << "1             内置地图" << endl;
        cout << "2             输入地图" << endl;

        cin >> instruct;
        if(instruct == 1){
            string temp;
            strcpy(_maze[0], "#######");
            strcpy(_maze[1], "#S#000#");
            strcpy(_maze[2], "#0#0###");
            strcpy(_maze[3], "#000#0#");
            strcpy(_maze[4], "#0#000#");
            strcpy(_maze[5], "#0#0#E#");
            strcpy(_maze[6], "#######");
            _start_point.x = 1;
            _start_point.y = 1;
            _end_point.x = 5;
            _end_point.y = 5;
            return 0;
        }

        cout << "请输入迷宫大小（要求为方阵）" << endl;
        cin >> _size;
        cout << "输入示例：" << endl;
        cout << "#######" << endl
             << "#S#000#" << endl
             << "#0#0###" << endl
             << "#000#0#" << endl
             << "#0#000#" << endl
             << "#0#0#E#" << endl
             << "#######" << endl;
        cout << "其中，S为起点，E为终点，0为道路，#为墙壁" << endl;
        cout << "请按照上述格式和约定输入地图" << endl;
        for (int i = 0; i < _size; ++i) {
            for (int j = 0; j < _size; ++j) {
                cin >> _maze[i][j];
                if(_maze[i][j] == 'S'){
                    _start_point.x = j;
                    _start_point.y = i;
                }
                if(_maze[i][j] == 'E'){
                    _end_point.x = j;
                    _end_point.y = i;
                }
                if(_maze[i][j] == '\n'){
                    cin >> _maze[i][j];
                }
            }
        }
        return 0;
    }

    void printMaze(){
        cout << "迷宫地图: " << endl << endl;
        cout << "\t";
        for (int i = 0; i < _size; ++i) {
            cout << "\t" << i << "列" ;
        }
        cout << endl;
        for (int j = 0; j < _size; ++j) {
            cout << "\t" << j << "行";
            for (int k = 0; k < _size; ++k) {
                cout << "\t" << _maze[j][k];
            }
            cout << endl;
        }
    }

    int size(void){
        return _size;
    }

    char at (Point in){
        return _maze[in.x][in.y];
    }
};
#endif //MAZE_MAZE_H
