#include <iostream>
#include <string>
#include <raylib.h>

int main(void){
    InitWindow(0,0,"AutoPilot");
    const int width = GetScreenWidth();
    const int height = GetScreenHeight();
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    SetTargetFPS(30);

    Image SettingImage = LoadImage("button_settings.png");
    ImageResize(&SettingImage, 200, 117);
    Texture SettingTexture = LoadTextureFromImage(SettingImage);
    UnloadImage(SettingImage);

    Image HomeImage = LoadImage("button_home.png");
    ImageResize(&HomeImage, 180, 180);
    Texture HomeTexture = LoadTextureFromImage(HomeImage);
    UnloadImage(HomeImage);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(GetColor(0x181818FF));
        DrawRectangle(0, 0, 300, height, GetColor(0x393939FF));
        DrawRectangleLinesEx({300.0, 0.0, static_cast<float>(width - 300.0), static_cast<float>(height - 0.1)}, 40, GetColor(0x00FF00FF));

        DrawTextureRec(SettingTexture, {0.0, 0.0, 200.0, 117.0}, {50.0, 35.0}, RAYWHITE);
        DrawTextureRec(HomeTexture, {0.0, 0.0, 180.0, 180.0}, {60.0, 860.0}, RAYWHITE);

        EndDrawing();
    }

    UnloadTexture(HomeTexture);
    UnloadTexture(SettingTexture);

    CloseWindow();

    return 0;
}
