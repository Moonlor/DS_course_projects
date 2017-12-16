//
//  main.cpp
//  Joseph_Game
//
//  Created by 李坤 on 2017/10/25.
//  Copyright © 2017年 李坤. All rights reserved.
//

#include <iostream>
#include "Circle.h"

int main(int argc, const char * argv[]) {
    Circle* game = new Circle();
    game->kill();
    game->showResult();
    return 0;
}
