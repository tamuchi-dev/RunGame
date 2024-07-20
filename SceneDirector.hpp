#pragma once
#include <memory>
#include "TitleScene.hpp"
#include "StageScene.hpp"
#include "ResultScene.hpp"
#include "CircleFade.hpp"

namespace Game
{
    class SceneDirector final
    {
        /* 現在動いているシーン */
        std::unique_ptr<Scene> nowScene;

        std::unique_ptr<CircleFade> fade;

        int BGM[4] = { 0 };

    public:
        enum
        {
            TitleBGM,
            StageBGM,
            ClearBGM,
            OverBGM,
        };

        /* 起動準備 */
        void Startup() noexcept;

        /* ゲームを終了するか？ */
        [[nodiscard]]
        bool IsExitGame() const noexcept;

        /* 更新処理 */
        void Update() const noexcept;

        /* 描画処理 */
        void Render() const noexcept;

        void ChangeBGM(int id);

        void StopBGM();

        /* シーンを切り替える */
        template <class SceneType>
        void ChangeScene() noexcept
        {
            /* 指定した型がシーンでないならアサートする */
            static_assert
            (
                std::is_base_of<Scene, SceneType>::value,
                "シーンの子クラスを指定してください。"
            );

            nowScene.reset();
            nowScene = std::make_unique<SceneType>();
            nowScene->Initialize();
        }

        /* 実体を取得 */
        [[nodiscard]]
        static SceneDirector& GetInstance() noexcept
        {
            static SceneDirector instance;

            return instance;
        }

        CircleFade* GetFade() { return fade.get(); }

    private:

        SceneDirector() = default;

        SceneDirector(const SceneDirector&) = delete;

        SceneDirector& operator=(const SceneDirector&) = delete;
    };
}
