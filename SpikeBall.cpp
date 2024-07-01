#include "SpikeBall.hpp"

namespace Game
{
    SpikeBall::SpikeBall() noexcept
    {
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/SpikeBall.png"));

        Initialize();
    }

    void SpikeBall::Initialize() noexcept
    {
        Obstacle::Initialize();

        sprite.scale = 3.0;

        position = Vector{ 0, 700 };

        colider = CircleColider{ position, 30 };
    }

    void SpikeBall::Update() noexcept
    {
        /* �A�N�e�B�u�łȂ��Ȃ珈������K�v������ */
        if (nowState == State::Inactive)
        {
            return;
        }

        Obstacle::Update();

        colider.Set(position);
    }
}
