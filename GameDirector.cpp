#include "GameDirector.hpp"
#include "ObjectDirector.hpp"
#include <DxLib.h>

namespace Game
{
    void GameDirector::Initialize() noexcept
    {
        nowScore = 0;

        nowTimeLimit = 90;

        elapsedDelta = 0;

        nowEvent = Event::None;

        nowLevel = 1;

        time = 75.4;
        wave = 471;
        time = 59.5;
        wave = 363;
        time = 0;
        wave = 0;

        blackSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/Black.png"));
        blackSprite.scale = 30;
        dir = 1;
        state = -1;
        alpha = 0;
        flg = 0;
    }

    void GameDirector::Render()
    {
        if (state != -1)
        {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
            blackSprite.Render(Vector{ (float64)Screen::sizeX / 2, (float64)Screen::sizeY / 2 });
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);
        }
    }

    void GameDirector::Update() noexcept
    {
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            nowEvent = Event::GameClear;
        }
        Stage();
        if (nowTimeLimit == 70 || nowTimeLimit == 30)
        {
            state = 0;
        }

        switch (state)
        {
        case 0:
            alpha = 0;
            dir = 1;
            state = 1;
            break;
        case 1:
            if (alpha += dir; alpha == 255)
            {
                state = 2;
            }
            break;
        case 2:
            if (flg == 0)
            {
                flg = 1;
                ObjectDirector::GetInstance().GetSkydomeManager()->ChangeSkydome<CloudDome>();
            }
            else
            {
                ObjectDirector::GetInstance().GetSkydomeManager()->ChangeSkydome<NightDome>();
            }
            state = 3;
            break;
        case 3:
            alpha = 255;
            dir = -1;
            state = 4;
            break;
        case 4:
            if (alpha += dir; alpha == 0)
            {
                state = -1;
            }
            break;
        }

        if (nowTimeLimit == 0)
        {
            nowEvent = Event::GameClear;
        }
        else
        {
            elapsedDelta += FrameRate::GetDeltaTime();

            // ˆê•bi‚ñ‚¾‚çˆê‚ÂƒJƒEƒ“ƒgƒ_ƒEƒ“‚·‚é
            if (elapsedDelta >= 1)
            {
                elapsedDelta = 0;
                --nowTimeLimit;
            }

            // 20•b‚²‚Æ‚ÉƒŒƒxƒ‹ƒAƒbƒv
            if (nowTimeLimit == 70 || nowTimeLimit == 50 || nowTimeLimit == 30 || nowTimeLimit == 10)
            {
                ++nowLevel;
                ObjectDirector::GetInstance().GetUIManager()->GetUI<LevelUp>()->Trigger();
            }
        }

        const auto& player = ObjectDirector::GetInstance().GetPlayer();

        /* ƒvƒŒƒCƒ„[‚ÆáŠQ•¨‚ÌÕ“Ë”»’è */
        {
            const auto& container = ObjectDirector::GetInstance().GetObstacleManager()->GetContainer();

            for (const auto& obstacle : container)
            {
                if (obstacle->GetState() == Obstacle::State::Inactive)
                {
                    continue;
                }

                /* “–‚½‚Á‚½‚çƒQ[ƒ€ƒI[ƒo[ƒCƒxƒ“ƒg‚ğ”­¶‚³‚¹‚é */
                if (CircleColider::IsCollision(player->GetColider(), obstacle->GetColider()))
                {
                    nowEvent = Event::GameOver;
                }
            }
        }

        /* ƒvƒŒƒCƒ„[‚ÆƒRƒCƒ“‚ÌÕ“Ë”»’è */
        {
            const auto& container = ObjectDirector::GetInstance().GetCoinManager()->GetContainer();

            for (const auto& coin : container)
            {
                if (coin->GetState() == Coin::State::Inactive)
                {
                    continue;
                }

                const auto& icon = ObjectDirector::GetInstance().GetUIManager()->GetUI<CharaIcon>();

                /* ƒvƒŒƒCƒ„[‚ÆÚG‚µ‚½‚çAŠl“¾ƒgƒŠƒK[‚ğ—§‚Ä‚é */
                if (coin->GetState() == Coin::State::Active && CircleColider::IsCollision(player->GetColider(), coin->GetColider()))
                {
                    coin->GetCoin();
                }

                /* Šl“¾‰‰o‚ªI—¹‚µ‚½‚çƒRƒCƒ“‚ğŠl“¾‚·‚é */
                if (coin->GetState() == Coin::State::Get && coin->GetPosition().y <= icon->GetPosition().y + 30)
                {
                    nowScore += coin->GetAcquisitionScore();

                    coin->Delete();
                }
            }
        }
    }

    void GameDirector::Stage() noexcept
    {
        time += FrameRate::GetDeltaTime();

        Level1();
        Level2();
        Level3();
        Level4();
        Level5();
    }

    void GameDirector::Level1() noexcept
    {
        auto obst = ObjectDirector::GetInstance().GetObstacleManager();
        auto coin = ObjectDirector::GetInstance().GetCoinManager();

        // Chain Coin
        if (time >= 0 && wave == 0)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 0.1 && wave == 1)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 0.2 && wave == 2)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 0.3 && wave == 3)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 0.4 && wave == 4)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 0.5 && wave == 5)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 0.6 && wave == 6)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }

        // Chain Coin
        else if (time >= 1 && wave == 7)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 1.1 && wave == 8)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 1.2 && wave == 9)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 1.3 && wave == 10)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 1.4 && wave == 11)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 1.5 && wave == 12)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 1.6 && wave == 13)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }

        // Chain Coin
        if (time >= 2 && wave == 14)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 2.1 && wave == 15)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 2.2 && wave == 16)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 2.3 && wave == 17)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 2.4 && wave == 18)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 2.5 && wave == 19)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 2.6 && wave == 20)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }

        // Chain Coin
        if (time >= 3 && wave == 21)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
        }
        else if (time >= 3.1 && wave == 22)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
        }
        else if (time >= 3.2 && wave == 23)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
        }
        else if (time >= 3.3 && wave == 24)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
        }
        else if (time >= 3.4 && wave == 25)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
        }
        else if (time >= 3.5 && wave == 26)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
        }
        else if (time >= 3.6 && wave == 27)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
        }

        // Spike
        else if (time >= 4 && wave == 28)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }

        // Road Coin
        if (time >= 4.5 && wave == 29)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 4.6 && wave == 30)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 4.7 && wave == 31)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 4.8 && wave == 32)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 4.9 && wave == 33)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 5 && wave == 34)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 5.1 && wave == 35)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 5.2 && wave == 36)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 5.3 && wave == 37)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 5.4 && wave == 38)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 5.5 && wave == 39)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 5.6 && wave == 40)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 5.7 && wave == 41)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 5.8 && wave == 42)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 5.85 && wave == 43)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }
        else if (time >= 5.9 && wave == 44)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 6 && wave == 45)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 6.1 && wave == 46)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 6.2 && wave == 47)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 6.3 && wave == 48)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 6.4 && wave == 49)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 6.5 && wave == 50)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 6.6 && wave == 51)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 6.7 && wave == 52)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 6.8 && wave == 53)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 6.9 && wave == 54)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 7 && wave == 55)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 7.1 && wave == 56)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 7.2 && wave == 57)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 7.3 && wave == 58)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 7.4 && wave == 59)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
        }
        else if (time >= 7.5 && wave == 60)
        {
            ++wave;
            coin->Generate<SilverCoin>(600);
        }
        else if (time >= 7.6 && wave == 61)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
        }
        else if (time >= 7.65 && wave == 62)
        {
            ++wave;
            obst->Generate<SpikeBall>();
        }
        else if (time >= 7.7 && wave == 63)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
        }
        else if (time >= 7.8 && wave == 64)
        {
            ++wave;
            coin->Generate<SilverCoin>(600);
        }
        else if (time >= 7.9 && wave == 65)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
        }
        else if (time >= 8 && wave == 66)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 8.1 && wave == 67)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 8.2 && wave == 68)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 8.3 && wave == 69)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }

        // Road Coin
        else if (time >= 9.5 && wave == 70)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
        }
        else if (time >= 9.6 && wave == 71)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
        }
        else if (time >= 9.7 && wave == 72)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
        }
        else if (time >= 9.8 && wave == 73)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
        }
        else if (time >= 9.9 && wave == 74)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
        }
        else if (time >= 10 && wave == 75)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
        }
        else if (time >= 10.1 && wave == 76)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
        }
        else if (time >= 10.2 && wave == 77)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 10.3 && wave == 78)
        {
            ++wave;
            coin->Generate<GoldCoin>(750);
        }
        else if (time >= 10.4 && wave == 79)
        {
            ++wave;
            coin->Generate<GoldCoin>(800);
        }
        else if (time >= 10.5 && wave == 80)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 10.6 && wave == 81)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 10.7 && wave == 82)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 10.8 && wave == 83)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 10.9 && wave == 84)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 11 && wave == 85)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }

        // Spike x2
        else if (time >= 11.5 && wave == 86)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }
        else if (time >= 12.5 && wave == 87)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }

        // Chain Coin 2
        else if (time >= 13.5 && wave == 88)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 13.6 && wave == 89)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 13.7 && wave == 90)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 13.8 && wave == 91)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 13.9 && wave == 92)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 14 && wave == 93)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 14.1 && wave == 94)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 14.2 && wave == 95)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 14.3 && wave == 96)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 14.4 && wave == 97)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 14.5 && wave == 98)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 14.6 && wave == 99)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 14.7 && wave == 100)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 14.8 && wave == 101)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(850);
        }

        // Spike x3
        else if (time >= 15.5 && wave == 102)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }
        else if (time >= 16.25 && wave == 103)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }
        else if (time >= 17 && wave == 104)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }
    }

    void GameDirector::Level2() noexcept
    {
        auto obst = ObjectDirector::GetInstance().GetObstacleManager();
        auto coin = ObjectDirector::GetInstance().GetCoinManager();

        // Level up
        if (time >= 18.5 && wave == 105)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<GoldCoin>(780);
            coin->Generate<RedCoin>(710);
        }
        else if (time >= 18.6 && wave == 106)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(780);
            coin->Generate<GoldCoin>(710);
        }
        else if (time >= 18.7 && wave == 107)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            coin->Generate<RedCoin>(780);
            coin->Generate<SilverCoin>(710);
        }
        else if (time >= 18.8 && wave == 108)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<GoldCoin>(780);
            coin->Generate<RedCoin>(710);
        }
        else if (time >= 18.9 && wave == 109)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(780);
            coin->Generate<GoldCoin>(710);
        }
        else if (time >= 19 && wave == 110)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            coin->Generate<RedCoin>(780);
            coin->Generate<SilverCoin>(710);
        }
        else if (time >= 19.1 && wave == 111)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<GoldCoin>(780);
            coin->Generate<RedCoin>(710);
        }
        else if (time >= 19.2 && wave == 112)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(780);
            coin->Generate<GoldCoin>(710);
        }
        else if (time >= 19.3 && wave == 113)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            coin->Generate<RedCoin>(780);
            coin->Generate<SilverCoin>(710);
        }
        else if (time >= 19.4 && wave == 114)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<GoldCoin>(780);
            coin->Generate<RedCoin>(710);
        }
        else if (time >= 19.5 && wave == 115)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(780);
            coin->Generate<GoldCoin>(710);
        }
        else if (time >= 19.6 && wave == 116)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            coin->Generate<RedCoin>(780);
            coin->Generate<SilverCoin>(710);
        }
        else if (time >= 19.7 && wave == 117)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<GoldCoin>(780);
            coin->Generate<RedCoin>(710);
        }
        else if (time >= 19.8 && wave == 118)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(780);
            coin->Generate<GoldCoin>(710);
        }
        else if (time >= 19.9 && wave == 119)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            coin->Generate<RedCoin>(780);
            coin->Generate<SilverCoin>(710);
        }
        else if (time >= 20 && wave == 120)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<GoldCoin>(780);
            coin->Generate<RedCoin>(710);
        }
        else if (time >= 20.1 && wave == 121)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(780);
            coin->Generate<GoldCoin>(710);
        }
        else if (time >= 20.2 && wave == 122)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            coin->Generate<RedCoin>(780);
            coin->Generate<SilverCoin>(710);
        }
        else if (time >= 20.3 && wave == 123)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<GoldCoin>(780);
            coin->Generate<RedCoin>(710);
        }
        else if (time >= 20.4 && wave == 124)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(780);
            coin->Generate<GoldCoin>(710);
        }
        else if (time >= 20.5 && wave == 125)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            coin->Generate<RedCoin>(780);
            coin->Generate<SilverCoin>(710);
        }
        else if (time >= 20.6 && wave == 126)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<GoldCoin>(780);
            coin->Generate<RedCoin>(710);
        }
        else if (time >= 20.7 && wave == 127)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(780);
            coin->Generate<GoldCoin>(710);
        }
        else if (time >= 20.8 && wave == 128)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            coin->Generate<RedCoin>(780);
            coin->Generate<SilverCoin>(710);
        }
        else if (time >= 20.9 && wave == 129)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<GoldCoin>(780);
            coin->Generate<RedCoin>(710);
        }
        else if (time >= 21 && wave == 130)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(780);
            coin->Generate<GoldCoin>(710);
        }
        else if (time >= 21.1 && wave == 131)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            coin->Generate<RedCoin>(780);
            coin->Generate<SilverCoin>(710);
        }
        else if (time >= 21.2 && wave == 132)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<GoldCoin>(780);
            coin->Generate<RedCoin>(710);
        }
        else if (time >= 21.3 && wave == 133)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(780);
            coin->Generate<GoldCoin>(710);
        }
        else if (time >= 21.4 && wave == 134)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            coin->Generate<RedCoin>(780);
            coin->Generate<SilverCoin>(710);
        }
        else if (time >= 21.5 && wave == 135)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<GoldCoin>(780);
            coin->Generate<RedCoin>(710);
        }
        else if (time >= 21.6 && wave == 136)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(780);
            coin->Generate<GoldCoin>(710);
        }
        else if (time >= 21.7 && wave == 137)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            coin->Generate<RedCoin>(780);
            coin->Generate<SilverCoin>(710);
        }

        // Spike & SpikeBall & Chain coin alt
        else if (time >= 22.5 && wave == 138)
        {
            ++wave;
            obst->Generate<SpikeBall>();
        }
        else if (time >= 22.8 && wave == 139)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 22.9 && wave == 140)
        {
            ++wave;
            coin->Generate<GoldCoin>(800);
        }
        else if (time >= 23 && wave == 141)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 23.1 && wave == 142)
        {
            ++wave;
            coin->Generate<GoldCoin>(800);
        }
        else if (time >= 23.2 && wave == 143)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 23.3 && wave == 144)
        {
            ++wave;
            coin->Generate<GoldCoin>(800);
        }
        else if (time >= 23.6 && wave == 145)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }
        else if (time >= 23.9 && wave == 146)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 24 && wave == 147)
        {
            ++wave;
            coin->Generate<GoldCoin>(750);
        }
        else if (time >= 24.1 && wave == 148)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 24.2 && wave == 149)
        {
            ++wave;
            coin->Generate<GoldCoin>(750);
        }
        else if (time >= 24.3 && wave == 150)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 24.4 && wave == 151)
        {
            ++wave;
            coin->Generate<GoldCoin>(750);
        }

        // Chain coin & SpikeBall
        else if (time >= 24.7 && wave == 152)
        {
            ++wave;
            coin->Generate<SilverCoin>(600);
        }
        else if (time >= 24.8 && wave == 153)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
        }
        else if (time >= 24.9 && wave == 154)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 25 && wave == 155)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 25.1 && wave == 156)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 25.2 && wave == 157)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 25.3 && wave == 158)
        {
            ++wave;
            obst->Generate<SpikeBall>();
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 25.4 && wave == 159)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 25.5 && wave == 160)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 25.6 && wave == 161)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 25.7 && wave == 162)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 25.8 && wave == 163)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
        }
        else if (time >= 25.9 && wave == 164)
        {
            ++wave;
            coin->Generate<SilverCoin>(600);
        }
        else if (time >= 26 && wave == 165)
        {
            ++wave;
            obst->Generate<SpikeBall>();
            coin->Generate<SilverCoin>(550);
        }
        else if (time >= 26.1 && wave == 166)
        {
            ++wave;
            coin->Generate<SilverCoin>(600);
        }
        else if (time >= 26.2 && wave == 167)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
        }
        else if (time >= 26.3 && wave == 168)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 26.4 && wave == 169)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 26.5 && wave == 170)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 26.6 && wave == 171)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 26.7 && wave == 172)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 26.8 && wave == 173)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 26.9 && wave == 174)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 27 && wave == 175)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 27.1 && wave == 176)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 27.2 && wave == 177)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 27.3 && wave == 178)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }

        // Ground Spike 3
        if (time >= 27.6 && wave == 179)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }
        else if (time >= 28.1 && wave == 180)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }
        else if (time >= 28.6 && wave == 181)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }

        // Chain Coin
        else if (time >= 29.3 && wave == 182)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 29.4 && wave == 183)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 29.5 && wave == 184)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 29.6 && wave == 185)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 29.7 && wave == 186)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 29.8 && wave == 187)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 29.9 && wave == 188)
        {
            ++wave;
            coin->Generate<RedCoin>(600);
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 30 && wave == 189)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 30.1 && wave == 190)
        {
            ++wave;
            coin->Generate<RedCoin>(750);
            coin->Generate<SilverCoin>(650);
        }
        else if (time >= 30.2 && wave == 191)
        {
            ++wave;
            coin->Generate<RedCoin>(800);
            coin->Generate<SilverCoin>(600);
        }
        else if (time >= 30.3 && wave == 192)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(550);
        }
        else if (time >= 30.4 && wave == 193)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(550);
        }
        else if (time >= 30.5 && wave == 194)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(550);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 30.6 && wave == 195)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(550);
        }
        else if (time >= 30.7 && wave == 196)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(550);
        }
        else if (time >= 30.8 && wave == 197)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(550);
        }
        else if (time >= 30.9 && wave == 198)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            coin->Generate<SilverCoin>(550);
        }

        // Ground Spike & Spike Ball
        else if (time >= 31.2 && wave == 199)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 31.3 && wave == 200)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 31.4 && wave == 201)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 31.5 && wave == 202)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 31.6 && wave == 203)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 31.7 && wave == 204)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 31.8 && wave == 205)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 31.9 && wave == 206)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 32 && wave == 207)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 32.1 && wave == 208)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 32.2 && wave == 209)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 32.3 && wave == 210)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 32.4 && wave == 211)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 32.5 && wave == 212)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 32.6 && wave == 213)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 32.7 && wave == 214)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 32.8 && wave == 215)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 32.9 && wave == 216)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 33 && wave == 217)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 33.1 && wave == 218)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }

        // Chain Coin
        else if (time >= 33.5 && wave == 219)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 33.6 && wave == 220)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 33.7 && wave == 221)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 33.8 && wave == 222)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 33.9 && wave == 223)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 34 && wave == 224)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 34.1 && wave == 225)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 34.2 && wave == 226)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
        }
        else if (time >= 34.3 && wave == 227)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 34.4 && wave == 228)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 34.5 && wave == 229)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 34.6 && wave == 230)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 34.7 && wave == 231)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 34.8 && wave == 232)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 35 && wave == 233)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }

        // Chain Coin & Spike Ball
        else if (time >= 35.5 && wave == 234)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 35.6 && wave == 235)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 35.7 && wave == 236)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 35.8 && wave == 237)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 36.3 && wave == 238)
        {
            ++wave;
            obst->Generate<SpikeBall>();
        }
        else if (time >= 36.8 && wave == 239)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 36.9 && wave == 240)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 37 && wave == 241)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 37.1 && wave == 242)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
    }

    void GameDirector::Level3() noexcept
    {
        auto obst = ObjectDirector::GetInstance().GetObstacleManager();
        auto coin = ObjectDirector::GetInstance().GetCoinManager();

        // levelup Ring 1
        if (time >= 40 && wave == 243)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 40.1 && wave == 244)
        {
            ++wave;
            coin->Generate<SilverCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 40.2 && wave == 245)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<GoldCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 40.3 && wave == 246)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<GoldCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 40.4 && wave == 247)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<GoldCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 40.5 && wave == 248)
        {
            ++wave;
            coin->Generate<SilverCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 40.6 && wave == 249)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
        }

        // levelup Ring 2
        else if (time >= 41 && wave == 250)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
        }
        else if (time >= 41.1 && wave == 251)
        {
            ++wave;
            coin->Generate<GoldCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<GoldCoin>(800);
        }
        else if (time >= 41.2 && wave == 252)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<RedCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<RedCoin>(800);
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 41.3 && wave == 253)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<RedCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<RedCoin>(800);
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 41.4 && wave == 254)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<RedCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<RedCoin>(800);
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 41.5 && wave == 255)
        {
            ++wave;
            coin->Generate<GoldCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<GoldCoin>(800);
        }
        else if (time >= 41.6 && wave == 256)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
        }

        // levelup Ring 3
        else if (time >= 42 && wave == 257)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
        }
        else if (time >= 42.1 && wave == 258)
        {
            ++wave;
            coin->Generate<RedCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<RedCoin>(800);
        }
        else if (time >= 42.2 && wave == 259)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 42.3 && wave == 260)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 42.4 && wave == 261)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 42.5 && wave == 262)
        {
            ++wave;
            coin->Generate<RedCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<RedCoin>(800);
        }
        else if (time >= 42.6 && wave == 263)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
        }

        // Between Trap
        else if (time >= 43.7 && wave == 264)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 43.8 && wave == 265)
        {
            ++wave;
            coin->Generate<RedCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 43.9 && wave == 266)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 44.2 && wave == 267)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 44.3 && wave == 268)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 44.4 && wave == 269)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 44.6 && wave == 270)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 44.7 && wave == 271)
        {
            ++wave;
            coin->Generate<RedCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 44.8 && wave == 272)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
            obst->Generate<GroundSpike>();
        }

        // Chain Coin alt
        else if (time >= 45.2 && wave == 273)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 45.25 && wave == 274)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 45.3 && wave == 275)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 45.35 && wave == 276)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 45.4 && wave == 277)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 45.45 && wave == 278)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 45.5 && wave == 279)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 45.55 && wave == 280)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 45.6 && wave == 281)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 45.65 && wave == 282)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 45.7 && wave == 283)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 45.75 && wave == 284)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }


        // Chain Coin alt & Ground Spike
        else if (time >= 46 && wave == 285)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 46.05 && wave == 286)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
        }
        else if (time >= 46.1 && wave == 287)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 46.15 && wave == 288)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 46.2 && wave == 289)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 46.25 && wave == 290)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
        }
        else if (time >= 46.3 && wave == 291)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 46.35 && wave == 292)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
        }
        else if (time >= 46.4 && wave == 293)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 46.45 && wave == 294)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 46.5 && wave == 295)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 46.55 && wave == 296)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
        }

        // Diamond Trap
        else if (time >= 47.3 && wave == 297)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 47.4 && wave == 298)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(750);
        }
        else if (time >= 47.5 && wave == 299)
        {
            ++wave;
            coin->Generate<RedCoin>(600);
            obst->Generate<SpikeBall>();
            coin->Generate<RedCoin>(800);
        }
        else if (time >= 47.6 && wave == 300)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(750);
        }
        else if (time >= 47.7 && wave == 301)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }

        // Chain Coin & Rotary Saw
        else if (time >= 48 && wave == 302)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 48.1 && wave == 303)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 48.2 && wave == 304)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 48.3 && wave == 305)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 48.4 && wave == 306)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 48.5 && wave == 307)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 48.6 && wave == 308)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 48.7 && wave == 309)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 48.8 && wave == 310)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 48.9 && wave == 311)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 49 && wave == 312)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 49.1 && wave == 313)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
        }
        else if (time >= 49.2 && wave == 314)
        {
            ++wave;
            coin->Generate<SilverCoin>(600);
            obst->Generate<RotarySaw>();
        }

        // Line Coin
        else if (time >= 49.8 && wave == 315)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 49.9 && wave == 316)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 50 && wave == 317)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 50.1 && wave == 318)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 50.2 && wave == 319)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 50.3 && wave == 320)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 50.4 && wave == 321)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 50.5 && wave == 322)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
        }
        else if (time >= 50.6 && wave == 323)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
        }
        else if (time >= 50.7 && wave == 324)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<GoldCoin>(800);
        }
        else if (time >= 50.8 && wave == 325)
        {
            ++wave;
            coin->Generate<GoldCoin>(750);
        }
        else if (time >= 50.9 && wave == 326)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 51 && wave == 327)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            obst->Generate<GroundSpike>();
        }

        // Some Ground Spike
        else if (time >= 51.5 && wave == 328)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 51.6 && wave == 329)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 51.7 && wave == 330)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 51.8 && wave == 331)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 51.9 && wave == 332)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 52 && wave == 333)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 52.1 && wave == 334)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 52.2 && wave == 335)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 52.3 && wave == 336)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        
        else if (time >= 52.4 && wave == 337)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 52.5 && wave == 338)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 52.6 && wave == 339)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 52.7 && wave == 340)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 52.8 && wave == 341)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 52.9 && wave == 342)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
            }
        else if (time >= 53 && wave == 343)
        {
            ++wave;
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 53.1 && wave == 344)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 53.2 && wave == 345)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }

        // Rotary Saw Trap
        else if (time >= 53.8 && wave == 346)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 53.9 && wave == 347)
        {
            ++wave;
            obst->Generate<RotarySaw>();
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 54 && wave == 348)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 54.1 && wave == 349)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<SilverCoin>(850);
        }

        else if (time >= 54.5 && wave == 350)
        {
            ++wave;
            coin->Generate<SilverCoin>(800);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 54.6 && wave == 351)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
        }
        else if (time >= 54.7 && wave == 352)
        {
            ++wave;
            coin->Generate<SilverCoin>(600);
        }
        else if (time >= 54.8 && wave == 353)
        {
            ++wave;
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 54.9 && wave == 354)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            obst->Generate<SpikeBall>();
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 55 && wave == 355)
        {
            ++wave;
            coin->Generate<GoldCoin>(500);
            coin->Generate<GoldCoin>(850);
        }

        else if (time >= 56 && wave == 356)
        {
            ++wave;
            obst->Generate<GroundSpike>();
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 56.2 && wave == 357)
        {
            ++wave;
            obst->Generate<GroundSpike>();
            coin->Generate<GoldCoin>(720);
        }
        else if (time >= 56.4 && wave == 358)
        {
            ++wave;
            obst->Generate<GroundSpike>();
            coin->Generate<GoldCoin>(740);
        }
        else if (time >= 56.8 && wave == 359)
        {
            ++wave;
            obst->Generate<SpikeBall>();
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 57 && wave == 360)
        {
            ++wave;
            obst->Generate<SpikeBall>();
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 57.2 && wave == 361)
        {
            ++wave;
            ++wave;
            obst->Generate<SpikeBall>();
            coin->Generate<SilverCoin>(850);
        }
    }

    void GameDirector::Level4() noexcept
    {
        auto obst = ObjectDirector::GetInstance().GetObstacleManager();
        auto coin = ObjectDirector::GetInstance().GetCoinManager();

        // level up
        // Silver diamond
        if (time >= 59.5 && wave == 363)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }
        else if (time >= 59.6 && wave == 364)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 59.7 && wave == 365)
        {
            ++wave;
            coin->Generate<SilverCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 59.8 && wave == 366)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
            coin->Generate<SilverCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 59.9 && wave == 367)
        {
            ++wave;
            coin->Generate<SilverCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(800);
        }
        else if (time >= 60 && wave == 368)
        {
            ++wave;
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 60.1 && wave == 369)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
        }

        // Gold diamond
        else if (time >= 60.3 && wave == 370)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 60.4 && wave == 371)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
        }
        else if (time >= 60.5 && wave == 372)
        {
            ++wave;
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<GoldCoin>(800);
        }
        else if (time >= 60.6 && wave == 373)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<GoldCoin>(800);
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 60.7 && wave == 374)
        {
            ++wave;
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<GoldCoin>(800);
        }
        else if (time >= 60.8 && wave == 375)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
        }
        else if (time >= 60.9 && wave == 376)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }

        // Red diamond
        else if (time >= 61.1 && wave == 377)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 61.2 && wave == 378)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
        }
        else if (time >= 61.3 && wave == 379)
        {
            ++wave;
            coin->Generate<RedCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<RedCoin>(800);
        }
        else if (time >= 61.4 && wave == 380)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<RedCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<RedCoin>(800);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 61.5 && wave == 381)
        {
            ++wave;
            coin->Generate<RedCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<RedCoin>(800);
        }
        else if (time >= 61.6 && wave == 382)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
        }
        else if (time >= 61.7 && wave == 383)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }

        // SpikeBall & GroundSpike Rush
        else if (time >= 62.5 && wave == 384)
        {
            ++wave;
            obst->Generate<GroundSpike>();
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 62.8 && wave == 385)
        {
            ++wave;
            obst->Generate<SpikeBall>();
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 63.1 && wave == 386)
        {
            ++wave;
            obst->Generate<GroundSpike>();
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 63.4 && wave == 387)
        {
            ++wave;
            obst->Generate<SpikeBall>();
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 63.7 && wave == 388)
        {
            ++wave;
            obst->Generate<GroundSpike>();
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 64 && wave == 389)
        {
            ++wave;
            obst->Generate<SpikeBall>();
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 64.3 && wave == 390)
        {
            ++wave;
            obst->Generate<GroundSpike>();
            coin->Generate<GoldCoin>(700);
        }

        // Red Coin Chain & Rotary Saw & GroundSpike Rush
        else if (time >= 64.8 && wave == 391)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
        }
        else if (time >= 64.9 && wave == 392)
        {
            ++wave;
            coin->Generate<RedCoin>(600);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 65 && wave == 393)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
        }
        else if (time >= 65.1 && wave == 394)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 65.2 && wave == 395)
        {
            ++wave;
            coin->Generate<RedCoin>(750);
        }
        else if (time >= 65.3 && wave == 396)
        {
            ++wave;
            coin->Generate<RedCoin>(800);
        }
        else if (time >= 65.4 && wave == 397)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 65.5 && wave == 398)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 65.6 && wave == 399)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            obst->Generate<RotarySaw>();
        }
        else if (time >= 65.7 && wave == 400)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 65.8 && wave == 401)
        {
            ++wave;
            coin->Generate<RedCoin>(800);
        }
        else if (time >= 65.9 && wave == 402)
        {
            ++wave;
            coin->Generate<RedCoin>(750);
        }
        else if (time >= 66 && wave == 403)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 66.1 && wave == 404)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 66.2 && wave == 405)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }

        // SpikeBall Trap
        else if (time >= 66.5 && wave == 406)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 66.6 && wave == 407)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 66.7 && wave == 408)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<RedCoin>(550);
            coin->Generate<RedCoin>(600);
        }
        else if (time >= 66.8 && wave == 409)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            coin->Generate<RedCoin>(550);
            coin->Generate<RedCoin>(600);
            obst->Generate<SpikeBall>();
        }

        // Box Trap
        else if (time >= 67.5 && wave == 410)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 67.6 && wave == 411)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 67.7 && wave == 412)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 67.8 && wave == 413)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 67.9 && wave == 414)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 68 && wave == 415)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 68.1 && wave == 416)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 68.2 && wave == 417)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 68.3 && wave == 418)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 68.4 && wave == 419)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 68.5 && wave == 420)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 68.6 && wave == 421)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 68.7 && wave == 422)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<SilverCoin>(850);
            obst->Generate<RotarySaw>();
        }
        else if (time >= 68.8 && wave == 423)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 68.9 && wave == 424)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 69 && wave == 425)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 69.1 && wave == 426)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 69.2 && wave == 427)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 69.3 && wave == 428)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
        }
        else if (time >= 69.4 && wave == 429)
        {
            ++wave;
            coin->Generate<GoldCoin>(650);
            coin->Generate<SilverCoin>(750);
        }

        // Red Chain
        else if (time >= 69.5 && wave == 430)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 69.6 && wave == 431)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 69.7 && wave == 432)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 69.8 && wave == 433)
        {
            ++wave;
            coin->Generate<RedCoin>(750);
        }
        else if (time >= 69.9 && wave == 434)
        {
            ++wave;
            coin->Generate<RedCoin>(800);
        }
        else if (time >= 70 && wave == 435)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 70.1 && wave == 436)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 70.2 && wave == 437)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 70.3 && wave == 438)
        {
            ++wave;
            coin->Generate<RedCoin>(800);
        }
        else if (time >= 70.4 && wave == 439)
        {
            ++wave;
            coin->Generate<RedCoin>(750);
        }
        else if (time >= 70.5 && wave == 440)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 70.6 && wave == 441)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 70.7 && wave == 442)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 70.8 && wave == 443)
        {
            ++wave;
            coin->Generate<RedCoin>(750);
        }
        else if (time >= 70.9 && wave == 444)
        {
            ++wave;
            coin->Generate<RedCoin>(800);
        }
        else if (time >= 71 && wave == 445)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            obst->Generate<RotarySaw>();
        }
        
        // Triple Obstracts
        else if (time >= 71.4 && wave == 446)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 71.5 && wave == 447)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 71.6 && wave == 448)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 71.7 && wave == 449)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 71.8 && wave == 450)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 72.2 && wave == 451)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 72.3 && wave == 452)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 72.4 && wave == 453)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 72.5 && wave == 454)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 72.6 && wave == 455)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 73 && wave == 456)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 73.1 && wave == 457)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 73.2 && wave == 458)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 73.3 && wave == 459)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 73.4 && wave == 460)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 73.8 && wave == 461)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 73.9 && wave == 462)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 74 && wave == 463)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 74.1 && wave == 464)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 74.2 && wave == 465)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 74.6 && wave == 466)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 74.7 && wave == 467)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 74.8 && wave == 468)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 74.9 && wave == 469)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
        }
        else if (time >= 75 && wave == 470)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
    }

    void GameDirector::Level5() noexcept
    {
        auto obst = ObjectDirector::GetInstance().GetObstacleManager();
        auto coin = ObjectDirector::GetInstance().GetCoinManager();

        // level up
        if (time >= 75.4 && wave == 471)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 75.8 && wave == 472)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 76.2 && wave == 473)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 76.6 && wave == 474)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 77 && wave == 475)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 77.4 && wave == 476)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 77.8 && wave == 477)
        {
            ++wave;
            coin->Generate<SilverCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 78.2 && wave == 478)
        {
            ++wave;
            coin->Generate<SilverCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 78.6 && wave == 479)
        {
            ++wave;
            coin->Generate<GoldCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 79 && wave == 480)
        {
            ++wave;
            coin->Generate<GoldCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 79.4 && wave == 481)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 79.8 && wave == 482)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }

        else if (time >= 80.1 && wave == 483)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 80.4 && wave == 484)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 80.7 && wave == 485)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 81 && wave == 486)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 81.3 && wave == 487)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 81.6 && wave == 488)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 81.9 && wave == 489)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 82 && wave == 490)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 82.1 && wave == 491)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 82.2 && wave == 492)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            obst->Generate<RotarySaw>();
        }
        else if (time >= 82.3 && wave == 493)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 82.4 && wave == 494)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 82.5 && wave == 495)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 82.6 && wave == 496)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 82.7 && wave == 497)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 82.8 && wave == 498)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 82.9 && wave == 499)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 83 && wave == 500)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 83.1 && wave == 501)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 83.2 && wave == 502)
        {
            ++wave;
            obst->Generate<SpikeBall>();
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 83.3 && wave == 503)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 83.4 && wave == 504)
        {
            ++wave;
            obst->Generate<SpikeBall>();
            obst->Generate<RotarySaw>();
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 83.5 && wave == 505)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 83.6 && wave == 506)
        {
            ++wave;
            obst->Generate<SpikeBall>();
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 83.8 && wave == 507)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 83.9 && wave == 508)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 84 && wave == 509)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 84.1 && wave == 510)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 84.2 && wave == 511)
        {
            ++wave;
            obst->Generate<GroundSpike>();
        }
        else if (time >= 84.3 && wave == 512)
        {
            ++wave;
            coin->Generate<RedCoin>(600);
            obst->Generate<SpikeBall>();
        }
        else if (time >= 84.4 && wave == 513)
        {
            ++wave;
            coin->Generate<RedCoin>(600);
        }
        else if (time >= 84.5 && wave == 514)
        {
            ++wave;
            coin->Generate<RedCoin>(650);
        }
        else if (time >= 84.6 && wave == 515)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 84.7 && wave == 516)
        {
            ++wave;
            coin->Generate<RedCoin>(750);
        }
        else if (time >= 84.8 && wave == 517)
        {
            ++wave;
            coin->Generate<RedCoin>(800);
        }
        else if (time >= 84.9 && wave == 518)
        {
            ++wave;
            coin->Generate<RedCoin>(850);
            obst->Generate<RotarySaw>();
        }
        else if (time >= 85 && wave == 519)
        {
            ++wave;
            coin->Generate<RedCoin>(800);
        }
        else if (time >= 85.1 && wave == 520)
        {
            ++wave;
            coin->Generate<RedCoin>(750);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 85.2 && wave == 521)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
        }
        else if (time >= 85.3 && wave == 522)
        {
            ++wave;
            coin->Generate<RedCoin>(700);
            obst->Generate<GroundSpike>();
        }
        else if (time >= 85.5 && wave == 523)
        {
            ++wave;
            obst->Generate<SpikeBall>();
        }
        else if (time >= 85.8 && wave == 524)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<RedCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<RedCoin>(800);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 85.9 && wave == 525)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<GoldCoin>(800);
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 86 && wave == 526)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
            coin->Generate<SilverCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 86.1 && wave == 527)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<RedCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<RedCoin>(800);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 86.2 && wave == 528)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<GoldCoin>(800);
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 86.3 && wave == 529)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
            coin->Generate<SilverCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 86.4 && wave == 530)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<RedCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<RedCoin>(800);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 86.5 && wave == 531)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<GoldCoin>(800);
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 86.6 && wave == 532)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
            coin->Generate<SilverCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 86.7 && wave == 533)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<RedCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<RedCoin>(800);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 86.8 && wave == 534)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<GoldCoin>(800);
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 86.9 && wave == 535)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
            coin->Generate<SilverCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 87 && wave == 536)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<RedCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<RedCoin>(800);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 87.1 && wave == 537)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<GoldCoin>(800);
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 87.2 && wave == 538)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
            coin->Generate<SilverCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 87.3 && wave == 539)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<RedCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<RedCoin>(800);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 87.4 && wave == 540)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<GoldCoin>(800);
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 87.5 && wave == 541)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
            coin->Generate<SilverCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
        else if (time >= 87.6 && wave == 542)
        {
            ++wave;
            coin->Generate<RedCoin>(550);
            coin->Generate<RedCoin>(600);
            coin->Generate<RedCoin>(650);
            coin->Generate<RedCoin>(700);
            coin->Generate<RedCoin>(750);
            coin->Generate<RedCoin>(800);
            coin->Generate<RedCoin>(850);
        }
        else if (time >= 87.7 && wave == 543)
        {
            ++wave;
            coin->Generate<GoldCoin>(550);
            coin->Generate<GoldCoin>(600);
            coin->Generate<GoldCoin>(650);
            coin->Generate<GoldCoin>(700);
            coin->Generate<GoldCoin>(750);
            coin->Generate<GoldCoin>(800);
            coin->Generate<GoldCoin>(850);
        }
        else if (time >= 87.8 && wave == 544)
        {
            ++wave;
            coin->Generate<SilverCoin>(550);
            coin->Generate<SilverCoin>(600);
            coin->Generate<SilverCoin>(650);
            coin->Generate<SilverCoin>(700);
            coin->Generate<SilverCoin>(750);
            coin->Generate<SilverCoin>(800);
            coin->Generate<SilverCoin>(850);
        }
    }
}
