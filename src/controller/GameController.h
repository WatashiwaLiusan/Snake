//
// Created by LiuProJiaJie on 2024/10/18.
//

#ifndef SNAKE_GAMECONTROLLER_H
#define SNAKE_GAMECONTROLLER_H
#include "..\object\SnakeBody.h"
#include "..\object\Snake.h"
#include "..\object\Apple.h"
#include <set>
class GameController {
private:
    bool gameOver = false;
    bool win = false;
    float time = 0;
    Snake *modelSnake{};
    Apple *modelApple{};
    Vector2 temp = {1,0};
public:
    GameController(Snake *modelSnake, Apple *modelApple);
    bool isGameOver();
    void move();
    void input();
    void detect();
    void moveApple();
    bool isWin();
    void begin();
};


#endif //SNAKE_GAMECONTROLLER_H
