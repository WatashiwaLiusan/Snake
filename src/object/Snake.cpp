//
// Created by LiuProJiaJie on 2024/10/15.
//
#include "Snake.h"

Vector2 Snake::addHead() {
    SnakeBody *newHead = new SnakeBody({direction.x*50 + this->head->getPosition().x,direction.y*50 + this->head->getPosition().y});
    newHead->next = head;
    newHead->prev = nullptr;
    head->prev = newHead;
    head = newHead;
    return head->getPosition();
}

Snake::Snake(float speed, Vector2 headPos, Vector2 direction,const Texture2D &texture) : speed(speed), direction(direction),texture(texture){
    head = new SnakeBody(headPos);
    tail = head;
    tailCount = 1;
    length = 2;
}

Snake::Snake() {}

Vector2 Snake::getDirection() {
    return this->direction;
}

SnakeBody* Snake::getHead() {
    return head;
}
