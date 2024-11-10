//
// Created by wrz666 on 2024/10/19.
//

#ifndef SNAKE_LAYER_H
#define SNAKE_LAYER_H
#include "../object/Snake.h"
#include "../object/Apple.h"
class Layer {
public :
    static void drawSnake(Snake &s);
    static void drawApple(Apple &a);
};


#endif //SNAKE_LAYER_H
