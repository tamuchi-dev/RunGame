#include <DxLib.h>
#include "SceneDirector.hpp"

namespace Game
{
    void SceneDirector::Startup() noexcept
    {
        nowScene = std::make_unique<TitleScene>();
        fade = std::make_unique<CircleFade>();

        BGM[0] = LoadSoundMem("Asset/Sound/titleBgm.wav");
        BGM[1] = LoadSoundMem("Asset/Sound/stageBgm.mp3");
        BGM[2] = LoadSoundMem("Asset/Sound/resultBgm.mp3");
        BGM[3] = LoadSoundMem("Asset/Sound/yume.mp3");
        nowScene->Initialize();
        fade->Initialize();
    }
    void SceneDirector::ChangeBGM(int id)
    {
        StopBGM();

        PlaySoundMem(BGM[id], DX_PLAYTYPE_LOOP);
    }
    void SceneDirector::StopBGM()
    {
        for (int i = 0; i < 4; ++i)
        {
            StopSoundMem(BGM[i]);
        }
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
