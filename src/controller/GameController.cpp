//
// Created by LiuProJiaJie on 2024/10/18.
//

#include "GameController.h"
void GameController::move() {
    if (time == 0){
        time = 100/modelSnake->speed;
        modelSnake->addHead();
    }
    time--;

}

GameController::GameController(Snake *modelSnake) {
    this->modelSnake = modelSnake;
}

void GameController::input() {
    if(IsKeyPressed(KEY_A) && modelSnake->getDirection().x != 1)
        modelSnake->direction = {-1,0};
    if(IsKeyPressed(KEY_W) && modelSnake->getDirection().y != 1)
        modelSnake->direction = {0,-1};
    if(IsKeyPressed(KEY_S) && modelSnake->getDirection().y != -1)
        modelSnake->direction = {0,1};
    if(IsKeyPressed(KEY_D) && modelSnake->getDirection().x != -1)
        modelSnake->direction = {1,0};
}

void GameController::detect() {
    //TODO 头出界

    //判断身体碰撞
    SnakeBody *sb = modelSnake->getHead();
    std::set<std::pair<int,int>> occupied;
    while(sb != nullptr){
        std::pair<int,int> pos = {sb->getPosition().x,sb->getPosition().y};
        if(occupied.contains(pos)){
            GameOver = true;
            break;
        }
        occupied.emplace(pos);
        sb = sb->next;
    }
}

bool GameController::IsGameOver() {
    return GameOver;
}
