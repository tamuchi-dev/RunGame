#include <cassert>
#include <DxLib.h>
#include "Debug.hpp"
#include "Screen.hpp"
#include "CircleColider.hpp"
#include "FrameRate.hpp"

namespace Game
{
    bool Debug::isEnable = false;

    void Debug::Enable() noexcept
    {
        ChangeWindowMode(true);
        isEnable = true;
    }

    void Debug::Disable() noexcept
    {
        ChangeWindowMode(false);
        isEnable = false;
    }

    void Debug::Log(int32 x, int32 y, const char* format, ...) noexcept
    {
        if (not isEnable)
        {
            return;
        }

        va_list args;
        va_start(args, format);
        char buffer[1024];
        vsprintf_s(buffer, format, args);

        DrawString(x, y, buffer, GetColor(0, 255, 0));

        va_end(args);
    }

    void Debug::ErrorMessageBox(const char* message) noexcept
    {
        if (not isEnable)
        {
            return;
        }

        MessageBox(nullptr, message, "Error", MB_ICONERROR | MB_OK);
        exit(EXIT_FAILURE);
    }

    void Debug::Render(const CircleColider& colider) noexcept
    {
        if (not isEnable)
        {
            return;
        }

        DrawCircle
        (
            static_cast<int32>(colider.x),
            static_cast<int32>(colider.y),
            static_cast<int32>(colider.r),
            GetColor(255, 0, 0),
            false
        );
    }

    void Debug::FrameRate() noexcept
    {
        if (not isEnable)
        {
            return;
        }

        Debug::Log(10, 10, "FPS: %d", FrameRate::nowFPS);
        Debug::Log(10, 30, "Delta Time: %lf", FrameRate::deltaTime);
        Debug::Log(10, 50, "Elapsed Time: %d", FrameRate::elapsedTime);
    }

    void Debug::BaseLine2D() noexcept
    {
        if (not isEnable)
        {
            return;
        }

        DrawLine(0, Screen::sizeY / 2, Screen::sizeX , Screen::sizeY / 2, GetColor(255, 0, 0));
        DrawLine(Screen::sizeX / 2, 0, Screen::sizeX / 2, Screen::sizeY, GetColor(255, 0, 0));
    }
}
