//
// Created by hcfa on 7/15/25.
//

#ifndef RAYLIBANDROID_SIDEBAR_H
#define RAYLIBANDROID_SIDEBAR_H

#include <cstdint>
#include <raylib.h>

class Sidebar {
public:
    Sidebar();

    void draw();

    ~Sidebar();
private:
    Texture _settingTexture{};
    Texture _homeTexture{};
    Color _baseColor{0x39, 0x39, 0x39, 0xFF};
    Color _goodColor{0xDA, 0xCA, 0x25, 0xFF};
    Color _warningColor{0xC9, 0x22, 0x31, 0xFF};
    Color _dangerColor{0xFF, 0xFF, 0xFF, 0x55};
    Font _interFont{};
    uint8_t _netStrength = 3;
};


#endif //RAYLIBANDROID_SIDEBAR_H
