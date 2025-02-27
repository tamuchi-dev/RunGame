#pragma once
#include "Obstacle.hpp"

namespace Game
{
    class GroundSpike final : public Obstacle
    {
        /* 当たり判定の位置を調整する */
        const Vector coliderOffset;

    public:

        [[nodiscard]]
        GroundSpike() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept override;

        /* 更新処理 */
        void Update() noexcept override;
    };
}
