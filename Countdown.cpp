#include "Countdown.hpp"

namespace Game
{
    Countdown::Countdown() noexcept
    {
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/Countdown/0.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/Countdown/1.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/Countdown/2.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/Countdown/3.png"));

        Initialize();
    }

    void Countdown::Initialize() noexcept
    {
        position = Vector{ 960, 500 };

        elapsedDelta = 0;

        nowCount = 0;
    }

    void Countdown::Update() noexcept
    {
        if (nowCount < sprite.GetTotal())
        {
            elapsedDelta += FrameRate::GetDeltaTime();

            // 経過時間が1秒進むと一カウントする
            if (elapsedDelta > nowCount + 1)
            {
                elapsedDelta = ++nowCount;
            }
        }
    }

    void Countdown::Render() const noexcept
    {
        // カウントダウンが終了したら、描画しない
        if (nowCount >= sprite.GetTotal())
        {
            return;
        }

        sprite.Render(position, nowCount);
    }
}
