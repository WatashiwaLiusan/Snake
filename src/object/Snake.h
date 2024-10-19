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

    SnakeBody *head{};
    SnakeBody *tail{};
    int tailCount{};
    int length{};
public:
    float speed;
    Vector2 direction{};
    Vector2 getDirection();
    Snake(float speed,Vector2 headPos,Vector2 direction,const Texture2D &texture);
    Snake();
    Vector2 addHead();
    Texture2D texture;
    SnakeBody* getHead();
};


#endif //SNAKE_SNAKE_H
