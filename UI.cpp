#include "UI.hpp"

namespace Game
{
    void UI::Initialize() noexcept
    {
        /* 何もしない */
    }

    void UI::Update() noexcept
    {
        /* 何もしない */
    }

    void UI::Render() const noexcept
    {
        sprite.Render(position);
    }
}
