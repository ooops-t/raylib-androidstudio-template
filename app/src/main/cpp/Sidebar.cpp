//
// Created by hcfa on 7/15/25.
//

#include "Sidebar.h"

Sidebar::Sidebar() {
    Image settingImage = LoadImage("button_settings.png");
    ImageResize(&settingImage, 200, 117);
    _settingTexture = LoadTextureFromImage(settingImage);
    UnloadImage(settingImage);

    Image homeImage = LoadImage("button_home.png");
    ImageResize(&homeImage, 180, 180);
    _homeTexture = LoadTextureFromImage(homeImage);
    UnloadImage(homeImage);

    _interFont = LoadFont("Inter-Regular.ttf");
}

void Sidebar::draw() {
    DrawRectangle(0, 0, 300, GetScreenHeight(), _baseColor);

    DrawTextureRec(_settingTexture, {0.0, 0.0, 200.0, 117.0}, {50.0, 35.0}, RAYWHITE);
    DrawTextureRec(_homeTexture, {0.0, 0.0, 180.0, 180.0}, {60.0, 860.0}, RAYWHITE);

    DrawRectangleRounded({30.0 + 4, 338.0 + 4, 100.0, 118.0}, 0.18, 0, GetColor(0xFFFFFFFF));
    DrawRectangleRec({30.0 + 4 + 20, 338.0 + 4, 240 - 30, 118.0}, _baseColor);
    DrawRectangleRoundedLinesEx({30.0, 338.0, 240.0, 126.0}, 0.20, 0, 2.0, GetColor(0xFFFFFF55));
    DrawTextEx(_interFont, "CONNECT\nOFFLINE", {30.0 + 55, 338+30}, 35, 0, WHITE);

    DrawRectangleRounded({30.0 + 4, 496.0 + 4, 100.0, 118.0}, 0.18, 0, GetColor(0xDACA25FF));
    DrawRectangleRec({30.0 + 4 + 20, 496.0 + 4, 240 - 30, 118.0}, _baseColor);
    DrawRectangleRoundedLinesEx({30.0, 496.0, 240.0, 126.0}, 0.20, 0, 2.0, GetColor(0xFFFFFF55));
    DrawTextEx(_interFont, "TEMP\nHIGH", {30.0 + 55, 496+30}, 35, 0, WHITE);

    DrawRectangleRounded({30.0 + 4, 654.0 + 4, 100.0, 118.0}, 0.18, 0, GetColor(0xC92231FF));
    DrawRectangleRec({30.0 + 4 + 20, 654.0 + 4, 240 - 30, 118.0}, _baseColor);
    DrawRectangleRoundedLinesEx({30.0, 654.0, 240.0, 126.0}, 0.20, 0, 2.0, GetColor(0xFFFFFF55));
    DrawTextEx(_interFont, "PANDA\nNO", {30.0 + 55, 654+30}, 35, 0, WHITE);

    for (int i = 0; i < 5; ++i) {
        DrawCircle(58 + 20 + i * 37, 196, 14, i < _netStrength ? WHITE : GetColor(0x545454FF));
    }

    DrawTextEx(_interFont, "WiFi", {58 + 20, 247}, 35, 0, WHITE);
}

Sidebar::~Sidebar() {
    UnloadTexture(_homeTexture);
    UnloadTexture(_settingTexture);
    UnloadFont(_interFont);
}
