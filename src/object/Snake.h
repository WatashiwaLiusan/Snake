//
// Created by LiuProJiaJie on 2024/10/15.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H
#include "SnakeBody.h"
#include "raylib.h"
#include <vector>

class Snake {
private:
    SnakeBody *head;
    SnakeBody *tail;
    Vector2 direction;
    int tailCount;
    int speed;
    int length;
public:
    Snake(int speed,Vector2 headPos,Vector2 direction);
    Vector2 addHead();
};


#endif //SNAKE_SNAKE_H
