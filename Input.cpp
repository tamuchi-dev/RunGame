#include <DxLib.h>
#include "Input.hpp"

namespace Game
{
    int32 Input::keyState[256]{ 0 };

    int32 Input::oldMouseState{ 0 };

    int32 Input::nowMouseState{ 0 };

    Vector Input::cursorPos{ 0, 0 };

    void Input::Update() noexcept
    {
        GetHitKeyStateAllEx(keyState);

        oldMouseState = nowMouseState;

        nowMouseState = GetMouseInput();

        int32 x = 0;
        int32 y = 0;

        GetMousePoint(&x, &y);

        cursorPos = Vector{ static_cast<float64>(x), static_cast<float64>(y) };
    }
}
