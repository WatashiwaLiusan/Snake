#include "raylib.h"
#include "object\Snake.h"
#include "object\Apple.h"
#include "controller\GameController.h"
#include "layer/Layer.h"

Texture2D AppleTexture;
Texture2D SnakeHeadTexture;
Texture2D SnakeTexture;
void init(){
    //AppleTexture = LoadTexture("image/apple.png");
    SnakeHeadTexture = LoadTexture("..\\images\\snake\\snake_head.png");
    SnakeTexture = LoadTexture("..\\images\\snake\\snake_body.png");
}

void mainMenu(){
    DrawText("Snake",250,1,100,GRAY);
    DrawRectangle(300,300,200,100,GREEN);
    DrawText("Start",345,333,40,GRAY);
    DrawRectangle(300,450,200,100,GREEN);
    DrawText("Score",340,480,40,GRAY);
    DrawRectangle(300,600,200,100,GREEN);
    DrawText("Exit",360,630,40,GRAY);
}

int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Snake Made By Liusan");
    SetTargetFPS(60);
    init();
    auto *s = new Snake(1,{100,500},{1,0},SnakeTexture);
    auto controller = new GameController(s);

    bool isGameStarted = false;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTextureEx(SnakeTexture, {1,1},0,1,BLACK);
        if(isGameStarted){
            for (int i = 0; i < 16; ++i) {
                DrawLine(0,i*50,800,i*50,BLACK);
                DrawLine(i*50,0,i*50,800,BLACK);
            }
            controller->input();
            controller->detect();
            controller->move();
            Layer::drawSnake(*s);
            if(controller->IsGameOver())
                isGameStarted = false;
            EndDrawing();
            continue;
        }
        //main menu
        mainMenu();
        Vector2 v = GetMousePosition();
        if(v.x >= 300 && v.x <= 500 && v.y >= 300 && v.y <= 400) {
            if (IsMouseButtonPressed(0))
                isGameStarted = true;
        }
        //main game
        EndDrawing();
    }
    CloseWindow();
    return 0;
}