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

        scoreSprite2.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/0.png"));
        scoreSprite2.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/1.png"));
        scoreSprite2.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/2.png"));
        scoreSprite2.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/3.png"));
        scoreSprite2.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/4.png"));
        scoreSprite2.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/5.png"));
        scoreSprite2.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/6.png"));
        scoreSprite2.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/7.png"));
        scoreSprite2.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/8.png"));
        scoreSprite2.Add(GraphLoader::LoadSprite("Asset/Sprite/TimeLimit/9.png"));

        coinIconSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/CoinIcon.png"));

        coinSp.Add(GraphLoader::LoadSprite("Asset/Sprite/RedCoin/01.png"));
        coinSp.Add(GraphLoader::LoadSprite("Asset/Sprite/GoldCoin/01.png"));
        coinSp.Add(GraphLoader::LoadSprite("Asset/Sprite/SilverCoin/01.png"));

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
        scoreSprite2.scale = 0.3;

        scorePos = Vector{ 550, 120 };

        coinIconPos = Vector{ 255, 120 };
        resultPoint = 0;
        resultUpPoint = 0;
        speed = 0;
        coinSp.scale = 2;
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

        {
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

        coinSp.Render(Vector{ 80, 230 }, 0);
        coinSp.Render(Vector{ 80, 290 }, 1);
        coinSp.Render(Vector{ 80, 350 }, 2);

        {
            std::string toStr = std::to_string(100);
            int strSizeX = static_cast<int>((toStr.length() - 1) * (carryOffsetX / 1.5));
            int digitCount = 0;

            for (auto elem : toStr)
            {
                int index = elem - '0';

                const Vector pos
                {
                    200.0 - strSizeX + digitCount++ * (carryOffsetX / 1.5),
                    230
                };

                scoreSprite2.Render(pos, index);
            }
        }

        {
            std::string toStr = std::to_string(50);
            int strSizeX = static_cast<int>((toStr.length() - 1) * (carryOffsetX / 1.5));
            int digitCount = 0;

            for (auto elem : toStr)
            {
                int index = elem - '0';

                const Vector pos
                {
                    200.0 - strSizeX + digitCount++ * (carryOffsetX / 1.5),
                    290
                };

                scoreSprite2.Render(pos, index);
            }
        }

        {
            std::string toStr = std::to_string(10);
            int strSizeX = static_cast<int>((toStr.length() - 1) * (carryOffsetX / 1.5));
            int digitCount = 0;

            for (auto elem : toStr)
            {
                int index = elem - '0';

                const Vector pos
                {
                    200.0 - strSizeX + digitCount++ * (carryOffsetX / 1.5),
                    350
                };

                scoreSprite2.Render(pos, index);
            }
        }
    }

    void Score::ResultRender() const
    {
        frameSprite.Render(Vector{ 1920 / 2 + GameDirector::GetInstance().GetScrollOffsetX(), 1080 / 2 });
        std::string toStr = std::to_string(resultUpPoint);
        int strSizeX = static_cast<int>((toStr.length() - 1) * carryOffsetX*3);
        int digitCount = 0;

        for (auto elem : toStr)
        {
            int index = elem - '0';

            const Vector pos
            {
                (float64)Screen::sizeX / 2 - strSizeX + digitCount++ * carryOffsetX*3 + 300 + GameDirector::GetInstance().GetScrollOffsetX(),
                (float64)Screen::sizeY / 2
            };

            scoreSprite.Render(pos, index);
        }
    }
}
