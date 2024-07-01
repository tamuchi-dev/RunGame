#include "CircleFade.hpp"

namespace Game
{
    CircleFade::CircleFade()
    {
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/01.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/02.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/03.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/04.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/05.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/06.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/07.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/08.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/09.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/10.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/11.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/12.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/13.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/14.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/15.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/16.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CircleFade/17.png"));

        Initialize();
    }

    void CircleFade::Initialize()
    {
        intervalFrame = 3;
        frameCounter = 0;
        nowID = sprite.GetTotal() - 1;
        state = State::FadeOutEnd;
    }

    void CircleFade::Update()
    {
        switch (state)
        {
        case State::FadeOutStart:
            frameCounter = 0;
            nowID = 0;
            state = State::FadeOut;
            break;
        case State::FadeOut:
            if (++frameCounter >= intervalFrame)
            {
                frameCounter = 0;
                if (++nowID >= sprite.GetTotal() - 1)
                {
                    nowID = sprite.GetTotal() - 1;
                    state = State::FadeOutEnd;
                }
            }
            break;
        case State::FadeInStart:
            frameCounter = 0;
            nowID = sprite.GetTotal() - 1;
            state = State::FadeIn;
            break;
        case State::FadeIn:
            if (++frameCounter >= intervalFrame)
            {
                frameCounter = 0;
                if (--nowID < 0)
                {
                    nowID = 0;
                    state = State::FadeInEnd;
                }
            }
            break;
        default:
            break;
        }
    }

    void CircleFade::Render()
    {
        sprite.Render(Vector{ (float64)Screen::sizeX / 2, (float64)Screen::sizeY / 2 }, nowID);
    }
}
