#include <DxLib.h>
#include "Countdown.hpp"

namespace Game
{
    Countdown::Countdown() noexcept
    {
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/Countdown/0.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/Countdown/1.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/Countdown/2.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/Countdown/3.png"));
        SE1 =LoadSoundMem("Asset/Sound/cursorBack.mp3");
        SE2 =LoadSoundMem("Asset/Sound/cursorEnter.mp3");

        Initialize();
    }

    void Countdown::Initialize() noexcept
    {
        position = Vector{ 960, 500 };

        sprite.scale = scaleMin;
        sprite.angle = rotaMax;

        elapsedDelta = 0;

        is = true;
        nowCount = 0;
    }

    void Countdown::Update() noexcept
    {
        scaleV += speed;
        sprite.scale += scaleV;
        rotaV += speed;
        sprite.angle -= rotaV;

        if (sprite.scale > scaleMax)
        {
            sprite.scale = scaleMax;
            scaleV = -scaleV * bounds;
        }
        if (sprite.angle < rotaMin)
        {
            sprite.angle = rotaMin;
            rotaV = -rotaV * bounds;
        }
        if (nowCount == 0 || nowCount == 1 || nowCount == 2 || nowCount == 3)
        {
            if (is)
            {
                is = false;
                if (nowCount == 3)
                {
                    PlaySoundMem(SE2, DX_PLAYTYPE_BACK);
                }
                else
                {
                    PlaySoundMem(SE1, DX_PLAYTYPE_BACK);
                }
            }
        }

        if (nowCount < sprite.GetTotal())
        {
            elapsedDelta += FrameRate::GetDeltaTime();

            // 経過時間が1秒進むと一カウントする
            if (elapsedDelta > nowCount + 1)
            {
                is = true;
                sprite.scale = 0;
                scaleV = 0;
                sprite.angle = rotaMax;
                rotaV = 0;

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
