//
// Created by LiuProJiaJie on 2024/10/16.
//

#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H
#include "raylib.h"

class SnakeBody {
private:
    Vector2 position{};
public:
    SnakeBody *next;
    SnakeBody *prev;
    SnakeBody();
    SnakeBody(Vector2 position);
    Vector2 getPosition();
};


#endif //SNAKE_SNAKEBODY_H
