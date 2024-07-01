#include <DxLib.h>
#include "Screen.hpp"

namespace Game
{
    int32 Screen::sizeX{ 640 };

    int32 Screen::sizeY{ 480 };

    bool Screen::Startup() noexcept
    {
        return DxLib_Init() || SetDrawScreen(DX_SCREEN_BACK);
    }

    bool Screen::Update() noexcept
    {
        return ScreenFlip() || ProcessMessage() || ClearDrawScreen();
    }

    void Screen::Cleanup() noexcept
    {
        DxLib_End();
    }

    void Screen::SetSize(int32 x, int32 y) noexcept
    {
        sizeX = x;
        sizeY = y;

        SetGraphMode(sizeX, sizeY, 32);
    }

    void Screen::SetName(const char* name) noexcept
    {
        SetMainWindowText(name);
    }
}
