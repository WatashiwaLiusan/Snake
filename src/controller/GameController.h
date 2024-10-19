//
// Created by LiuProJiaJie on 2024/10/18.
//

#ifndef SNAKE_GAMECONTROLLER_H
#define SNAKE_GAMECONTROLLER_H
#include "..\object\SnakeBody.h"
#include "..\object\Snake.h"
#include "..\object\Apple.h"
#include "../view/GameView.h"
class GameController {
private:
    bool GameOver = false;
    std::vector<Vector2> memory = {{100,500}};
    float time = 0;
    Snake modelSnake{};
    Apple modelApple{};
public:
    GameController(Snake modelSnake);
    bool IsGameOver();
    void move();
    void input();
    void detect();
    void draw(Texture2D texture,std::vector<Vector2> pos);
};


#endif //SNAKE_GAMECONTROLLER_H
