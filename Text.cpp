#include "Text.hpp"

namespace Game
{
    void Text::Initialize() noexcept
    {
        /* 何もしない */
    }

    void Text::Update() noexcept
    {
        /* 何もしない */
    }

    void Text::Render() const noexcept
    {
        sprite.Render(position);
    }
}
