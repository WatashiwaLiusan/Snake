//
// Created by LiuProJiaJie on 2024/10/15.
//
#include "Snake.h"

void Snake::addHead() {
    SnakeBody *newHead = new SnakeBody({direction.x*50 + this->head->getPosition().x,direction.y*50 + this->head->getPosition().y});
    newHead->next = head;
    newHead->prev = nullptr;
    head->prev = newHead;
    head = newHead;
}

Snake::Snake(float speed, Vector2 headPos, Vector2 direction,const Texture2D &texture) : speed(speed), direction(direction),texture(texture){
    head = new SnakeBody(headPos);
    tail = head;
    tailCount = 1;
    length = 255;
}

Snake::Snake() {}

Vector2 Snake::getDirection() {
    return this->direction;
}

SnakeBody* Snake::getHead() {
    return head;
}

void Snake::tailCountMinus() {
    tailCount--;
}

int Snake::getTailCount() {
    return tailCount;
}


void Snake::removeTail() {
    this->tail = this->tail->prev;
    this->tail->next = nullptr;
}

void Snake::tailCountPlus() {
    this->tailCount++;
}

int Snake::addLength() {
    this->length++;
    return this->length;
}
