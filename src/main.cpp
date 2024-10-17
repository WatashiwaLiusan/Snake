#include "raylib.h"

void mainMenu(){
    DrawText("Snake",250,100,100,GRAY);
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
    bool isGameStarted = false;
    InitWindow(screenWidth, screenHeight, "Snake Made By Liusan");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        //main menu
        mainMenu();
        Vector2 v = GetMousePosition();
        if(v.x >= 300 && v.x <= 500 && v.y >= 300 && v.y <= 400)
            DrawText("Snake",250,100,1,GRAY);
            if(IsMouseButtonPressed(0))
                isGameStarted = true;
        //main game
        while(isGameStarted){
            BeginDrawing();
            ClearBackground(RAYWHITE);
            for (int i = 0; i < 16; ++i) {
                DrawLine(0,i*50,800,i*50,BLACK);
                DrawLine(i*50,0,i*50,800,BLACK);
            }
            EndDrawing();
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}