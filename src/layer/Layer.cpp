//
// Created by wrz666 on 2024/10/19.
//

#include "Layer.h"

void Layer::drawSnake(Snake &s) {
    SnakeBody* body = s.getHead();
    while (body != nullptr){
        DrawTextureEx(s.texture,body->getPosition(),0,1,RAYWHITE);
        body = body->next;
    }
}
