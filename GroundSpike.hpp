#pragma once
#include "Obstacle.hpp"

namespace Game
{
    class GroundSpike final : public Obstacle
    {
        /* �����蔻��̈ʒu�𒲐����� */
        const Vector coliderOffset;

    public:

        [[nodiscard]]
        GroundSpike() noexcept;

        /* ���������� */
        void Initialize() noexcept override;

        /* �X�V���� */
        void Update() noexcept override;
    };
}
