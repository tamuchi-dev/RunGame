#pragma once
#include "Obstacle.hpp"

namespace Game
{
    class SpikeBall final : public Obstacle
    {
    public:

        [[nodiscard]]
        SpikeBall() noexcept;

        /* ���������� */
        void Initialize() noexcept override;

        /* �X�V���� */
        void Update() noexcept override;
    };
}
