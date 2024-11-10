//
// Created by LiuProJiaJie on 2024/10/18.
//

#include "GameController.h"
void GameController::move() {
    if (time == 0){
        time = 100/modelSnake->speed;
        modelSnake->addHead();
        if(modelSnake->getTailCount() != 0){
            modelSnake->tailCountMinus();
        } else {
            modelSnake->removeTail();
        }
    }
    time--;
}



void GameController::input() {
    if(IsKeyPressed(KEY_A) && modelSnake->getDirection().x != 1)
        temp = {-1,0};
    if(IsKeyPressed(KEY_W) && modelSnake->getDirection().y != 1)
        temp = {0,-1};
    if(IsKeyPressed(KEY_S) && modelSnake->getDirection().y != -1)
        temp = {0,1};
    if(IsKeyPressed(KEY_D) && modelSnake->getDirection().x != -1)
        temp = {1,0};
    if(time == 0){
        modelSnake->direction = temp;
    }
}

void GameController::moveApple(){
    modelApple->position.x = GetRandomValue(1,15)*50;
    modelApple->position.y = GetRandomValue(1,15)*50;
}

void GameController::detect() {

    //头出界
    if(modelSnake->getHead()->getPosition().x < 0  || modelSnake->getHead()->getPosition().x >= 800  ||
            modelSnake->getHead()->getPosition().y < 0 || modelSnake->getHead()->getPosition().y >= 800){
        gameOver = true;
    }

    //判断身体碰撞
    SnakeBody *sb = modelSnake->getHead();
    std::set<std::pair<int,int>> occupied;
    while(sb != nullptr){
        std::pair<int,int> pos = {sb->getPosition().x,sb->getPosition().y};
        if(occupied.contains(pos)){
            gameOver = true;
            break;
        }
        occupied.emplace(pos);
        sb = sb->next;
    }

    //吃到苹果
    if (modelSnake->getHead()->getPosition().x == modelApple->getPosition().x && modelSnake->getHead()->getPosition().y == modelApple->getPosition().y){
        modelSnake->tailCountPlus();
        if(modelSnake->addLength() == 256)
            win = true;
        moveApple();
    }
}

bool GameController::isGameOver() {
    return gameOver;
}

GameController::GameController(Snake *modelSnake, Apple *modelApple) {
    this->modelSnake = modelSnake;
    this->modelApple = modelApple;
}

bool GameController::isWin() {
    return this->win;
}

void GameController::begin() {
    this->win = false;
}

