#include <fstream>
#include <sstream>
#include <algorithm>
#include <DxLib.h>
#include "GameDirector.hpp"
#include "Ranking.hpp"

namespace Game
{
    Ranking::Ranking() noexcept
    {
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

        frameSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/ScoreFrame.png"));

        for (auto& elem : ranking)
        {
            elem = 0;
        }

        Initialize();
    }

    void Ranking::Initialize() noexcept
    {
        scoreSprite.scale = 0.5;
        nowAlpha = 0;
        addAlphaValue = 3;
    }

    void Ranking::Update() noexcept
    {
        
    }

    void Ranking::Render() const noexcept
    {
        for (int i = 0; i < ranking.size(); ++i)
        {
            if (ranking[i] == GameDirector::GetInstance().GetNowScore())
            {
                nowAlpha += addAlphaValue;

                if (nowAlpha <= 0 || nowAlpha >= 255)
                {
                    addAlphaValue *= -1;
                }
                SetDrawBlendMode(DX_BLENDMODE_ALPHA, nowAlpha);
            }

            DrawRotaGraph3(
                int(1920 / 2 + 1500 + GameDirector::GetInstance().GetScrollOffsetX()) - 300,
                int(150 + (i * 150)) - 75,
                0,
                0,
                1.4,
                1.0,
                0.0,
                frameSprite.GetHandle(),
                TRUE
            );

            scoreSprite.Render(Vector{ 700 + 1500 + GameDirector::GetInstance().GetScrollOffsetX(), float(150 + (i * 150)) }, i + 1);

            RenderScore(900, float(150 + (i * 150)), ranking[i]);
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
        }

        DrawRotaGraph3(
            int(1920 / 2 + 1500 + GameDirector::GetInstance().GetScrollOffsetX()) - 300,
            580,
            0,
            0,
            1.4,
            1.0,
            0.0,
            frameSprite.GetHandle(),
            TRUE
        );
        RenderScore(900, 650, GameDirector::GetInstance().GetNowScore());
    }

    void Ranking::LoadRanking() noexcept
    {
        std::ifstream file{ "SaveData/Ranking.txt" };
        std::string line;

        if (file.is_open())
        {
            while (std::getline(file, line))
            {
                std::stringstream ss{ line };
                std::string cell;

                for (int i = 0; i < ranking.size(); ++i)
                {
                    std::getline(ss, cell, ',');

                    ranking[i] = std::stoi(cell);
                }
            }
        }
    }

    void Ranking::UpdateRanking() noexcept
    {
        std::array<int, 4> tempRanking
        {
            ranking[0],
            ranking[1],
            ranking[2],
            GameDirector::GetInstance().GetNowScore(),
        };

        std::sort(tempRanking.begin(), tempRanking.end(), std::greater<int>{});

        std::ofstream file{ "SaveData/Ranking.txt" };

        if (file.is_open())
        {
            for (int i = 0; i < ranking.size(); ++i)
            {
                file << tempRanking[i];
                ranking[i] = tempRanking[i];

                if (i < ranking.size() - 1)
                {
                    file << ',';
                }
            }
        }

        std::sort(ranking.begin(), ranking.end(), std::greater<int>{});
    }

    void Ranking::RenderScore(float x, float y, int score) const noexcept
    {
        std::string toStr = std::to_string(score);
        int strSizeX = static_cast<int>((toStr.length() - 1) * 50);
        int digitCount = 0;

        for (auto elem : toStr)
        {
            int index = elem - '0';

            auto pos = Vector{
                x - strSizeX + digitCount++ * 50 + 300 + 1500 + GameDirector::GetInstance().GetScrollOffsetX(),
                y,
                0
            };

            scoreSprite.Render(pos, index);
        }
    }
}
