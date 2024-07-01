#include "LevelUp.hpp"

namespace Game
{
    LevelUp::LevelUp() noexcept
    {
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/LevelUp.png"));

        Initialize();
    }

    void LevelUp::Initialize() noexcept
    {
        position = Vector{ 2300, 370 };

        scrollSpeed = 800;

        outScreenX = -800;

        nowState = State::Inactive;
    }

    void LevelUp::Update() noexcept
    {
        if (nowState == State::Inactive)
        {
            return;
        }

        position.x -= scrollSpeed * FrameRate::GetDeltaTime();

        if (position.x < outScreenX)
        {
            nowState = State::Inactive;
        }
    }

    void LevelUp::Render() const noexcept
    {
        if (nowState == State::Inactive)
        {
            return;
        }

        sprite.Render(position);
    }

    void LevelUp::Trigger() noexcept
    {
        if (nowState == State::Inactive)
        {
            Initialize();

            nowState = State::Active;
        }
    }
}
