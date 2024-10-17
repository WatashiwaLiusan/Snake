//
// Created by LiuProJiaJie on 2024/10/15.
//
#include "Snake.h"

Vector2 Snake::addHead() {
    SnakeBody *newHead = new SnakeBody({direction.x + this->head->getPosition().x,direction.y + this->head->getPosition().y});
    newHead->next = head;
    newHead->prev = NULL;
    head->prev = newHead;
    head = newHead;
    return head->getPosition();
}

Snake::Snake(int speed, Vector2 headPos, Vector2 direction) : speed(speed), direction(direction){
    head = new SnakeBody(headPos);
    tail = head;
    tailCount = 1;
    length = 2;
}

