#pragma once
#include "Obstacle.hpp"

namespace Game
{
    class SpikeBall final : public Obstacle
    {
    public:

        [[nodiscard]]
        SpikeBall() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept override;

        /* 更新処理 */
        void Update() noexcept override;
    };
}
