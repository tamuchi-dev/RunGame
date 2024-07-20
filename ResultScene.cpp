#include "Framework.hpp"
#include <DxLib.h>
#include "ObjectDirector.hpp"
#include "SceneDirector.hpp"
#include "GameDirector.hpp"

namespace Game
{
    ResultScene::ResultScene()
    {
        gameOver.Add(GraphLoader::LoadSprite("Asset/Sprite/GameOverText.png"));
        gameClear.Add(GraphLoader::LoadSprite("Asset/Sprite/GameClearText.png"));
        gameClearW.Add(GraphLoader::LoadSprite("Asset/Sprite/GameClearW.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/01.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/02.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/03.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/04.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/05.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/06.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/07.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/08.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/09.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/10.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/11.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/12.png"));
        confettiSp.Add(GraphLoader::LoadSprite("Asset/Sprite/Confetti/13.png"));

        first = false;
        gameOver.scale = 0.6;
        gameClear.scale = 0.6;
        gameClearW.scale = 0.6;

        Initialize();
        if (GameDirector::GetInstance().GetNowEvent() == GameDirector::Event::GameClear)
        {
            SceneDirector::GetInstance().ChangeBGM(SceneDirector::ClearBGM);
        }
        else
        {
            SceneDirector::GetInstance().ChangeBGM(SceneDirector::OverBGM);
        }

        ObjectDirector::GetInstance().GetUIManager()->GetUI<Ranking>()->LoadRanking();
    }

    void ResultScene::Initialize() noexcept
    {
        ObjectDirector::GetInstance().GetSkydomeManager()->ChangeSkydome<SunnyDome>();
        ObjectDirector::GetInstance().GetPlayer()->Initialize();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<Score>()->InResult();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<Ranking>()->Initialize();

        first = false;

        gameOverY = -200;
        gameOverVY = 0;
        for (int i = 0; i < 100; ++i)
        {
            confetti[i].index = 0;
            confetti[i].interval = 0;
            confetti[i].pos.x = 0;
            confetti[i].pos.y = 0;
            confetti[i].isVisible = false;
        }
        gameOverGravity = 300;
        gameClear.scale = 0.2f;
        gameClearVS = 0;
        gameClearAddS = 0.1f;
        gameClearWX = 0;
        gameClearEffFrame = 0;
        isShowRanking = false;
        timer = 0;
        isPress = false;
    }

    void ResultScene::Transition() const noexcept
    {
        if (isShowRanking && Input::IsMouseButtonDown(MouseCode::ButtonL))
        {
            SceneDirector::GetInstance().GetFade()->FadeInStart();
        }

        if (first && SceneDirector::GetInstance().GetFade()->IsFadeInEnd())
        {
            SceneDirector::GetInstance().ChangeScene<TitleScene>();
        }
    }

    void ResultScene::Update() noexcept
    {
        if (not first && SceneDirector::GetInstance().GetFade()->IsFadeInEnd())
        {
            first = true;
            SceneDirector::GetInstance().GetFade()->FadeOutStart();
            ObjectDirector::GetInstance().GetUIManager()->GetUI<Ranking>()->UpdateRanking();
        }

        ObjectDirector::GetInstance().GetSkydomeManager()->Update();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<Score>()->Update();

        if (SceneDirector::GetInstance().GetFade()->IsFadeOutEnd())
        {
            if (not isPress && Input::IsMouseButtonDown(MouseCode::ButtonL))
            {
                isPress = true;
            }
        }

        if (isPress)
        {
            GameDirector::GetInstance().Scroll();

            if (GameDirector::GetInstance().GetScrollOffsetX() <= -1500)
            {
                isShowRanking = true;
            }
        }

        if (GameDirector::GetInstance().GetNowEvent() == GameDirector::Event::GameClear)
        {
            if (SceneDirector::GetInstance().GetFade()->IsFadeOutEnd())
            {
                UpdateGameClear();
            }
            ObjectDirector::GetInstance().GetPlayer()->ClearUpdate();
        }
        else
        {
            if (SceneDirector::GetInstance().GetFade()->IsFadeOutEnd())
            {
                UpdateGameOver();
            }
            ObjectDirector::GetInstance().GetPlayer()->OverUpdate();
        }
    }

    void ResultScene::Render() const noexcept
    {
        ObjectDirector::GetInstance().GetSkydomeManager()->Render();
        ObjectDirector::GetInstance().GetGround()->Render();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<Score>()->ResultRender();
        for (int i = 0; i < 100; ++i)
        {
            if (not confetti[i].isVisible)
            {
                continue;
            }

            confettiSp.Render(confetti[i].pos, confetti[i].index);
        }
        if (GameDirector::GetInstance().GetNowEvent() == GameDirector::Event::GameClear)
        {
            if (SceneDirector::GetInstance().GetFade()->IsFadeOutEnd())
            {
                gameClear.Render(Vector{ 1920 / 2 + GameDirector::GetInstance().GetScrollOffsetX(), 150});
                if (gameClearEffFrame >= 100)
                {
                    SetDrawArea(500 + (int)gameClearWX, 0, 550 + (int)gameClearWX, 300);
                    gameClearW.Render(Vector{ 1920 / 2 + GameDirector::GetInstance().GetScrollOffsetX(), 150 });
                    SetDrawArea(0, 0, 1920, 1080);
                }
            }
        }
        else
        {
            gameOver.Render(Vector{ 1920 / 2 + GameDirector::GetInstance().GetScrollOffsetX(), gameOverY });
        }
        ObjectDirector::GetInstance().GetUIManager()->GetUI<Ranking>()->Render();
        if (GameDirector::GetInstance().GetNowEvent() == GameDirector::Event::GameClear)
        {
            ObjectDirector::GetInstance().GetPlayer()->Render();
        }
        else
        {
            ObjectDirector::GetInstance().GetPlayer()->OverRender();
        }
    }

    void ResultScene::UpdateGameOver() noexcept
    {
        gameOverVY += gameOverGravity * (float)FrameRate::GetDeltaTime();
        gameOverY += gameOverVY;

        if (gameOverY > 150)
        {
            gameOverY = 150;
            gameOverVY = -gameOverVY * 0.6f;
        }
    }

    void ResultScene::UpdateGameClear() noexcept
    {
        gameClearVS += gameClearAddS * (float)FrameRate::GetDeltaTime();
        gameClear.scale += gameClearVS;

        if (++gameClearEffFrame >= 100)
        {
            gameClearWX += 300 * (float)FrameRate::GetDeltaTime();
            if (gameClearWX > 1450)
            {
                gameClearWX = 0;
            }
        }

        if (gameClear.scale > 0.6f)
        {
            gameClear.scale = 0.6f;
            gameClearVS = -gameClearVS * 0.6f;
        }

        if (++timer >= 10)
        {
            timer = 0;

            for (int i = 0; i < 100; ++i)
            {
                if (not confetti[i].isVisible)
                {
                    confetti[i].pos.x = GetRand(1920);
                    confetti[i].pos.y = -20;
                    confetti[i].interval = 0;
                    confetti[i].index = 0;
                    confetti[i].isVisible = true;
                    break;
                }
            }
        }

        for (int i = 0; i < 100; ++i)
        {
            if (not confetti[i].isVisible)
            {
                continue;
            }

            if (confetti[i].pos.y += 500 * FrameRate::GetDeltaTime(); confetti[i].pos.y >= 1090)
            {
                confetti[i].isVisible = false;
            }

            if (++confetti[i].interval >= 10)
            {
                confetti[i].interval = 0;

                if (++confetti[i].index >= 13)
                {
                    confetti[i].index = 0;
                }
            }
        }
    }
}
