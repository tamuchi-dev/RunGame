#include "Framework.hpp"
#include<DxLib.h>
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

        first = false;
        gameOver.scale = 0.6;
        gameClear.scale = 0.6;
        gameClearW.scale = 0.6;

        Initialize();
    }

    void ResultScene::Initialize() noexcept
    {
        ObjectDirector::GetInstance().GetSkydomeManager()->ChangeSkydome<SunnyDome>();
        ObjectDirector::GetInstance().GetPlayer()->Initialize();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<Score>()->InResult();

        first = false;

        gameOverY = -200;
        gameOverVY = 0;
        gameOverGravity = 300;
        gameClear.scale = 0.2f;
        gameClearVS = 0;
        gameClearAddS = 0.1f;
        gameClearWX = 0;
        gameClearEffFrame = 0;
    }

    void ResultScene::Transition() const noexcept
    {
        if (Input::IsMouseButtonDown(MouseCode::ButtonL))
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
        if (not first &&SceneDirector::GetInstance().GetFade()->IsFadeInEnd())
        {
            first = true;
            SceneDirector::GetInstance().GetFade()->FadeOutStart();
        }

        ObjectDirector::GetInstance().GetSkydomeManager()->Update();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<Score>()->Update();

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
        if (GameDirector::GetInstance().GetNowEvent() == GameDirector::Event::GameClear)
        {
            ObjectDirector::GetInstance().GetPlayer()->Render();
            if (SceneDirector::GetInstance().GetFade()->IsFadeOutEnd())
            {
                gameClear.Render(Vector{ 1920 / 2, 250 });
                if (gameClearEffFrame >= 100)
                {
                    SetDrawArea(500 + (int)gameClearWX, 200, 550 + (int)gameClearWX, 300);
                    gameClearW.Render(Vector{ 1920 / 2, 250 });
                    SetDrawArea(0, 0, 1920, 1080);
                }
            }
        }
        else
        {
            ObjectDirector::GetInstance().GetPlayer()->OverRender();
            gameOver.Render(Vector{ 1920 / 2, gameOverY });
        }
    }

    void ResultScene::UpdateGameOver() noexcept
    {
        gameOverVY += gameOverGravity * (float)FrameRate::GetDeltaTime();
        gameOverY += gameOverVY;

        if (gameOverY > 250)
        {
            gameOverY = 250;
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
    }
}
