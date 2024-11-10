#include "raylib.h"
#include "object\Snake.h"
#include "object\Apple.h"
#include "controller\GameController.h"
#include "layer/Layer.h"
#include <fstream>

Texture2D AppleTexture;
Texture2D SnakeHeadTexture;
Texture2D SnakeTexture;
void init(){
    SnakeHeadTexture = LoadTexture(R"(..\images\snake\snake_head.png)");
    SnakeTexture = LoadTexture(R"(..\images\snake\snake_body.png)");
    AppleTexture = LoadTexture("..\\images\\apple.png");
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
    std::ifstream InFile("score.txt");
    std::ofstream OFile("score.txt");
    const int screenWidth = 800;
    const int screenHeight = 800;
    int score;
    InitWindow(screenWidth, screenHeight, "Snake Made By Liusan");
    SetTargetFPS(60);
    init();
    InFile >> score;
    InFile.close();
    score++;
    OFile << score;
    OFile.close();
    auto *s = new Snake(4,{100,350},{1,0},SnakeTexture);
    auto *a = new Apple({static_cast<float>(GetRandomValue(1,15)*50), static_cast<float>(GetRandomValue(1,15)*50)},AppleTexture);
    auto controller = new GameController(s,a);
    bool isGameStarted = false;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        //game started
        if(isGameStarted){
            for (int i = 0; i < 16; ++i) {
                DrawLine(0,i*50,800,i*50,BLACK);
                DrawLine(i*50,0,i*50,800,BLACK);
            }
            controller->input();
            controller->detect();
            controller->move();
            Layer::drawSnake(*s);
            Layer::drawApple(*a);
            if(controller->isGameOver())
                isGameStarted = false;
            if(controller->isWin()){
                isGameStarted = false;
            }
            EndDrawing();
            continue;
        }
        //main menu
        mainMenu();
        Vector2 v = GetMousePosition();
        if(v.x >= 300 && v.x <= 500 && v.y >= 300 && v.y <= 400 &&  isGameStarted == false) {
            if (IsMouseButtonPressed(0)){
                isGameStarted = true;
            }
        }
        if(controller->isWin()){
            score++;
            OFile << score;
            OFile.close();
            controller->begin();
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}