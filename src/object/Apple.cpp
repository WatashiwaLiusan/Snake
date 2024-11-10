//
// Created by LiuProJiaJie on 2024/10/16.
//

#include "Apple.h"

Apple::Apple(Vector2 pos,const Texture2D &texture) : position(pos),texture(texture){}

Vector2 Apple::getPosition() {
    return this->position;
}
