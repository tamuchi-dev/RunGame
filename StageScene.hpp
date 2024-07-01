#pragma once
#include "Scene.hpp"

namespace Game
{
    class StageScene final : public Scene
    {
        enum class State
        {
            /* カウントダウン中 */
            Coutdown,

            /* ゲーム中 */
            NowGame,

            GameOver,
        };

        /* 現在の状態 */
        State nowState;

    public:

        /* 初期化処理 */
        void Initialize() noexcept override;

        /* シーン遷移処理 */
        void Transition() const noexcept override;

        /* 更新処理 */
        void Update() noexcept override;

        /* 描画処理 */
        void Render() const noexcept override;
    };
}
