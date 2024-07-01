#include "TitleLogo.hpp"

namespace Game
{
    TitleLogo::TitleLogo() noexcept
    {
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TitleLogo.png"));

        Initialize();
    }

    void TitleLogo::Initialize() noexcept
    {
        position = Vector{ 960, 250 };
    }

    void TitleLogo::Render() const noexcept
    {
        sprite.Render(position);
    }
}
