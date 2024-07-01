#include "CharaIcon.hpp"

namespace Game
{
    CharaIcon::CharaIcon() noexcept
    {
        iconSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CharaIcon.png"));
        frameSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/IconFrame.png"));

        Initialize();
    }

    void CharaIcon::Initialize() noexcept
    {
        iconSprite.scale = 3;
        
        frameSprite.scale = 1.3;

        iconPos = Vector{ 120, 115 };

        framePos = Vector{ 120, 120 };
    }

    void CharaIcon::Update() noexcept
    {
    }

    void CharaIcon::Render() const noexcept
    {
        frameSprite.Render(framePos);
        iconSprite.Render(iconPos);
    }
}
