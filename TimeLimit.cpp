#include "GameDirector.hpp"
#include "TimeLimit.hpp"

namespace Game
{
    TimeLimit::TimeLimit() noexcept
    {
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/0.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/1.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/2.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/3.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/4.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/5.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/6.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/7.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/8.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/9.png"));

        Initialize();
    }

    void TimeLimit::Initialize() noexcept
    {
        position = Vector{ 960, 200 };

        carryOffsetX = 100;

        sprite.scale = 1;
    }

    void TimeLimit::Update() noexcept
    {
    }

    void TimeLimit::Render() const noexcept
    {
        std::string toStr = std::to_string(GameDirector::GetInstance().GetNowTimeLimit());
        int strSizeX = static_cast<int>((toStr.length() - 1) * carryOffsetX);
        int digitCount = 0;

        for (auto elem : toStr)
        {
            int index = elem - '0';

            const Vector pos
            {
                position.x - strSizeX / 2 + digitCount++ * carryOffsetX,
                position.y
            };

            sprite.Render(pos, index);
        }
    }
}
