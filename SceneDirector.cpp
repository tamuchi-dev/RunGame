#include "SceneDirector.hpp"

namespace Game
{
    void SceneDirector::Startup() noexcept
    {
        nowScene = std::make_unique<TitleScene>();
        fade = std::make_unique<CircleFade>();
        nowScene->Initialize();
        fade->Initialize();
    }

    bool SceneDirector::IsExitGame() const noexcept
    {
        return nowScene->IsExitGame();
    }

    void SceneDirector::Update() const noexcept
    {
        nowScene->Transition();
        nowScene->Update();
        fade->Update();
    }

    void SceneDirector::Render() const noexcept
    {
        nowScene->Render();
        fade->Render();
    }
}
