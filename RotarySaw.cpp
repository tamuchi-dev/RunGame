#include "RotarySaw.hpp"

namespace Game
{
    RotarySaw::RotarySaw() noexcept
    {
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RotarySaw/01.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RotarySaw/02.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RotarySaw/03.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RotarySaw/04.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RotarySaw/05.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RotarySaw/06.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RotarySaw/07.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/RotarySaw/08.png"));

        Initialize();
    }

    void RotarySaw::Initialize() noexcept
    {
        Obstacle::Initialize();

        sprite.scale = 4.0;

        animation = Animation{ 0.1 };

        position = Vector{ 0, 780 };

        colider = CircleColider{ position, 65 };

        dir = 1;
    }

    void RotarySaw::Update() noexcept
    {
        /* アクティブでないなら処理する必要が無い */
        if (nowState == State::Inactive)
        {
            return;
        }

        Obstacle::Update();

        position.y += dir * 100 * FrameRate::GetDeltaTime();
        if (position.y < 780 - 100 || position.y > 780 + 100)
        {
            dir *= -1;
        }

        animation.PlayLoop(sprite);

        colider.Set(position);
    }

    void RotarySaw::Render() const noexcept
    {
        /* アクティブでないなら処理する必要が無い */
        if (nowState == State::Inactive)
        {
            return;
        }

        sprite.Render(position, animation.GetNowAnimID());
    }
}
