#pragma once
#include "Obstacle.hpp"

namespace Game
{
    class SpikeBall final : public Obstacle
    {
    public:

        [[nodiscard]]
        SpikeBall() noexcept;

        /* ‰Šú‰»ˆ— */
        void Initialize() noexcept override;

        /* XVˆ— */
        void Update() noexcept override;
    };
}
