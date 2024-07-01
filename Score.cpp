#include "GameDirector.hpp"
#include "Score.hpp"

namespace Game
{
    Score::Score() noexcept
    {
        frameSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/ScoreFrame.png"));

        scoreSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/0.png"));
        scoreSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/1.png"));
        scoreSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/2.png"));
        scoreSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/3.png"));
        scoreSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/4.png"));
        scoreSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/5.png"));
        scoreSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/6.png"));
        scoreSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/7.png"));
        scoreSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/8.png"));
        scoreSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/9.png"));

        coinIconSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CoinIcon.png"));

        frameSprite.scale = 0.9;
        scoreSprite.scale = 0.4;
        coinIconSprite.scale = 0.7;

        carryOffsetX = 40;

        Initialize();
    }

    void Score::Initialize() noexcept
    {
        framePos = Vector{ 400, 120 };
        frameSprite.scale = 0.9;

        count = 0;
        scoreSprite.scale = 0.4;
        inter = 2;

        scorePos = Vector{ 550, 120 };

        coinIconPos = Vector{ 255, 120 };
        resultPoint = 0;
        resultUpPoint = 0;
        speed = 0;
    }

    void Score::Update() noexcept
    {
        scoreSprite.scale = 1;

        if (++count >= inter)
        {
            count = 0;
            if (resultUpPoint += speed; resultUpPoint >= resultPoint)
            {
                resultUpPoint = resultPoint;
            }
        }
    }

    void Score::InResult()
    {
        resultPoint = GameDirector::GetInstance().GetNowScore();

        frameSprite.scale = 2;

        if (resultPoint >= 100000)
        {
            speed = 1000;
        }
        else if (resultPoint >= 5000)
        {
            speed = 500;
        }
        else if (resultPoint >= 1000)
        {
            speed = 100;
        }
        else if (resultPoint >= 100)
        {
            speed = 10;
        }
        else
        {
            speed = 1;
        }
    }

    void Score::Render() const noexcept
    {
        frameSprite.Render(framePos);

        coinIconSprite.Render(coinIconPos);

        std::string toStr = std::to_string(GameDirector::GetInstance().GetNowScore());
        int strSizeX = static_cast<int>((toStr.length() - 1) * carryOffsetX);
        int digitCount = 0;

        for (auto elem : toStr)
        {
            int index = elem - '0';

            const Vector pos
            {
                scorePos.x - strSizeX + digitCount++ * carryOffsetX,
                scorePos.y
            };

            scoreSprite.Render(pos, index);
        }
    }

    void Score::ResultRender() const
    {
        frameSprite.Render(Vector{ (float64)Screen::sizeX / 2, (float64)Screen::sizeY / 2});
        std::string toStr = std::to_string(resultUpPoint);
        int strSizeX = static_cast<int>((toStr.length() - 1) * carryOffsetX*3);
        int digitCount = 0;

        for (auto elem : toStr)
        {
            int index = elem - '0';

            const Vector pos
            {
                (float64)Screen::sizeX / 2 - strSizeX + digitCount++ * carryOffsetX*3 + 300,
                (float64)Screen::sizeY / 2
            };

            scoreSprite.Render(pos, index);
        }
    }
}
