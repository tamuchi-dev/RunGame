#pragma once
#include "Obstacle.hpp"

namespace Game
{
    class GroundSpike final : public Obstacle
    {
        /* “–‚½‚è”»’è‚ÌˆÊ’u‚ğ’²®‚·‚é */
        const Vector coliderOffset;

    public:

        [[nodiscard]]
        GroundSpike() noexcept;

        /* ‰Šú‰»ˆ— */
        void Initialize() noexcept override;

        /* XVˆ— */
        void Update() noexcept override;
    };
}
