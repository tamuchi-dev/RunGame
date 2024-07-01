#include "Framework.hpp"
#include "ObjectDirector.hpp"
#include "SceneDirector.hpp"
#include "GameDirector.hpp"

namespace Game
{
    ResultScene::ResultScene()
    {
        gameOver.Add(GraphLoader::LoadSprite("Asset/Sprite/GameOverText.png"));
        gameClear.Add(GraphLoader::LoadSprite("Asset/Sprite/GameClearText.png"));

        first = false;
        gameOver.scale = 0.6;
        gameClear.scale = 0.6;
    }

    void ResultScene::Initialize() noexcept
    {
        ObjectDirector::GetInstance().GetSkydomeManager()->ChangeSkydome<SunnyDome>();
        ObjectDirector::GetInstance().GetPlayer()->Initialize();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<Score>()->InResult();

        first = false;
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
            ObjectDirector::GetInstance().GetPlayer()->ClearUpdate();
        }
        else
        {
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
            gameClear.Render(Vector{ 1920 / 2, 250 });
        }
        else
        {
            ObjectDirector::GetInstance().GetPlayer()->OverRender();
            gameOver.Render(Vector{ 1920 / 2, 250 });
        }
    }
}
