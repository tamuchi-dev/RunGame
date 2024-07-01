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
        /* アクティブでないなら処理する必要が無い */
        if (nowState == State::Inactive)
        {
            return;
        }

        position.x -= moveSpeed * FrameRate::GetDeltaTime();

        /* 画面外に出たら削除する */
        if (position.x < outScreenX)
        {
            nowState = State::Inactive;
        }
    }

    void Obstacle::Render() const noexcept
    {
        /* アクティブでないなら処理する必要が無い */
        if (nowState == State::Inactive)
        {
            return;
        }

        sprite.Render(position);
    }
}
