#include <DxLib.h>
#include "Framework.hpp"
#include "ObjectDirector.hpp"
#include "SceneDirector.hpp"

namespace Game
{
    void TitleScene::Initialize() noexcept
    {
        ObjectDirector::GetInstance().GetPlayer()->Initialize();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<PleaseLeftClick>()->Initialize();
        ObjectDirector::GetInstance().GetSkydomeManager()->ChangeSkydome<SunnyDome>();
        SceneDirector::GetInstance().ChangeBGM(SceneDirector::TitleBGM);
    }

    bool TitleScene::IsExitGame() const noexcept
    {
        return Input::IsKeyDown(KeyCode::Escape);
    }

    void TitleScene::Transition() const noexcept
    {
        if (Input::IsMouseButtonDown(MouseCode::ButtonL))
        {
            SceneDirector::GetInstance().ChangeScene<StageScene>();
        }
    }

    void TitleScene::Update() noexcept
    {
        if (SceneDirector::GetInstance().GetFade()->IsFadeInEnd())
        {
            SceneDirector::GetInstance().GetFade()->FadeOutStart();
        }

        ObjectDirector::GetInstance().GetSkydomeManager()->Update();
        ObjectDirector::GetInstance().GetGround()->Update();
        ObjectDirector::GetInstance().GetPlayer()->Update();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<PleaseLeftClick>()->Update();
    }

    void TitleScene::Render() const noexcept
    {
        ObjectDirector::GetInstance().GetSkydomeManager()->Render();
        ObjectDirector::GetInstance().GetGround()->Render();
        ObjectDirector::GetInstance().GetPlayer()->Render();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<TitleLogo>()->Render();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<PleaseLeftClick>()->Render();
    }
}
