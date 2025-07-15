#include <iostream>
#include <string>
#include <raylib.h>

#include "Sidebar.h"

int main(void){
    InitWindow(0,0,"AutoPilot");
    const int width = GetScreenWidth();
    const int height = GetScreenHeight();
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    SetTargetFPS(30);

    Sidebar sidebar;
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(GetColor(0x181818FF));

        sidebar.draw();
        DrawRectangleLinesEx({300.0, 0.0, static_cast<float>(width - 300.0), static_cast<float>(height - 0.1)}, 40, GetColor(0x00FF00FF));

//        DrawRectangleLinesEx({0.0, 0.0, static_cast<float>(width), static_cast<float>(height - 0.1)}, 40, GetColor(0x00FF00FF));

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
