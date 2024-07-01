#pragma once
#include "Scene.hpp"

namespace Game
{
    class TitleScene final : public Scene
    {
    public:

        /* 初期化処理 */
        void Initialize() noexcept override;

        /* ゲームを終了するか？ */
        [[nodiscard]]
        bool IsExitGame() const noexcept override;

        /* シーン遷移処理 */
        void Transition() const noexcept override;

        /* 更新処理 */
        void Update() noexcept override;

        /* 描画処理 */
        void Render() const noexcept override;
    };
}
