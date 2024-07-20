#include "GrassGround.hpp"

namespace Game
{
    GrassGround::GrassGround() noexcept
    : length{ 26 }
    , scrollSpeed{ 600 }
    , outScreenX{ -5600 }
    , renderOffset{ 220, 0 }
    , pushBackX{ 2500 }
    {
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/GrassGround.png"));

        Initialize();
    }

    void GrassGround::Initialize() noexcept
    {
        sprite.scale = 5;

        positionLhs = Vector{ 80, 1000 };

        positionRhs = Vector{ pushBackX, 1000 };
    }

    void GrassGround::Update() noexcept
    {
        const auto speed = scrollSpeed * FrameRate::GetDeltaTime();

        const auto Scroll = [=](float64& positionX)
        {
            positionX -= speed;

            /* ��ʊO�ɏo���牟���߂� */
            if (positionX < outScreenX)
            {
                positionX = pushBackX;
            }
        };

        Scroll(positionLhs.x);
        Scroll(positionRhs.x);
    }

    void GrassGround::Render() const noexcept
    {
        for (int i = 0; i < length; ++i)
        {
            /* renderOffset.y�͕K��0�Ȃ̂ŁA���̂܂�i���|���Ė�薳�� */
            sprite.Render(positionLhs + renderOffset * i);
            sprite.Render(positionRhs + renderOffset * i);
        }
    }
}
