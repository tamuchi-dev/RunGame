#include "Obstacle.hpp"

namespace Game
{
    void Obstacle::Initialize() noexcept
    {
        nowState = State::Inactive;
    }

    void Obstacle::Generate() noexcept
    {
        if (nowState == State::Inactive)
        {
            Initialize();

            nowState = State::Active;
            position.x = 2000;
        }
    }

    void Obstacle::Update() noexcept
    {
        /* �A�N�e�B�u�łȂ��Ȃ珈������K�v������ */
        if (nowState == State::Inactive)
        {
            return;
        }

        position.x -= moveSpeed * FrameRate::GetDeltaTime();

        /* ��ʊO�ɏo����폜���� */
        if (position.x < outScreenX)
        {
            nowState = State::Inactive;
        }
    }

    void Obstacle::Render() const noexcept
    {
        /* �A�N�e�B�u�łȂ��Ȃ珈������K�v������ */
        if (nowState == State::Inactive)
        {
            return;
        }

        sprite.Render(position);
    }
}
