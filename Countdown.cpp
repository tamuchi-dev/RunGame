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

            // �o�ߎ��Ԃ�1�b�i�ނƈ�J�E���g����
            if (elapsedDelta > nowCount + 1)
            {
                elapsedDelta = ++nowCount;
            }
        }
    }

    void Countdown::Render() const noexcept
    {
        // �J�E���g�_�E�����I��������A�`�悵�Ȃ�
        if (nowCount >= sprite.GetTotal())
        {
            return;
        }

        sprite.Render(position, nowCount);
    }
}
