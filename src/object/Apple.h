//
// Created by LiuProJiaJie on 2024/10/16.
//

#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H
#include "raylib.h"

class Apple {
public:
    Vector2 position;
    Apple(Vector2 pos,const Texture2D &texture);
    Texture2D texture;
    Vector2 getPosition();
};


#endif //SNAKE_APPLE_H
