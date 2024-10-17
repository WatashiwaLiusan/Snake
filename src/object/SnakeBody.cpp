//
// Created by LiuProJiaJie on 2024/10/16.
//

#include "SnakeBody.h"

SnakeBody::SnakeBody() {
}

SnakeBody::SnakeBody(Vector2 position) : position(position){}

Vector2 SnakeBody::getPosition() {
    return this->position;
}


