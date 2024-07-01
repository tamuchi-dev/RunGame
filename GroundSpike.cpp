#include "GroundSpike.hpp"

namespace Game
{
    GroundSpike::GroundSpike() noexcept
    : coliderOffset{ 0, 35 }
    {
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/GroundSpike.png"));

        Initialize();
    }

    void GroundSpike::Initialize() noexcept
    {
        Obstacle::Initialize();

        sprite.scale = 5.0;

        position = Vector{ 0, 845 };

        colider = CircleColider{ position + coliderOffset, 25 };
    }

    void GroundSpike::Update() noexcept
    {
        /* アクティブでないなら処理する必要が無い */
        if (nowState == State::Inactive)
        {
            return;
        }

        Obstacle::Update();

        colider.Set(position + coliderOffset);
    }
}
