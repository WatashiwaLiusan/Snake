//
// Created by LiuProJiaJie on 2024/10/16.
//

#include "SnakeBody.h"

SnakeBody::SnakeBody() {
    this->next = nullptr;
    this->prev = nullptr;
}

SnakeBody::SnakeBody(Vector2 position) : position(position){
    this->next = nullptr;
    this->prev = nullptr;
}

Vector2 SnakeBody::getPosition() {
    return this->position;
}


