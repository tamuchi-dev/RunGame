#pragma once
#include "Obstacle.hpp"

namespace Game
{
    class RotarySaw final : public Obstacle
    {
        /* アニメーション */
        Animation animation;

        float64 dir;

    public:

        [[nodiscard]]
        RotarySaw() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept override;

        /* 更新処理 */
        void Update() noexcept override;

        /* 描画処理 */
        void Render() const noexcept override;
    };
}
