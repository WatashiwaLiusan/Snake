//
// Created by LiuProJiaJie on 2024/10/18.
//

#include "GameController.h"

void GameController::move() {
    if (time == 0){
        time = 100/modelSnake.speed;
        memory.push_back(modelSnake.addHead());
        draw(modelSnake.texture,memory);
    }
    time--;

}

GameController::GameController(Snake modelSnake) {
    this->modelSnake = modelSnake;
}

void GameController::input() {
    if(IsKeyPressed(KEY_A) && modelSnake.getDirection().x != 1)
        modelSnake.direction = {-1,0};
    if(IsKeyPressed(KEY_W) && modelSnake.getDirection().y != 1)
        modelSnake.direction = {0,-1};
    if(IsKeyPressed(KEY_S) && modelSnake.getDirection().y != -1)
        modelSnake.direction = {0,1};
    if(IsKeyPressed(KEY_D) && modelSnake.getDirection().x != -1)
        modelSnake.direction = {1,0};
}

void GameController::detect() {
    for (int i = 0; i < memory.size(); ++i) {
        for (int j = i; j < memory.size(); ++j) {
            if(memory[i].x == memory[j].x && memory[i].y == memory[j].y)
                GameOver = true;
        }
    }
}

bool GameController::IsGameOver() {
    return GameOver;
}


void GameController::draw(Texture2D texture, std::vector<Vector2> pos) {
    for (int i = 0; i < pos.size(); ++i) {
        DrawTextureEx(texture,pos[i],0,1,WHITE);
    }

}
