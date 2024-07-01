#pragma once
#include "Obstacle.hpp"

namespace Game
{
    class RotarySaw final : public Obstacle
    {
        /* �A�j���[�V���� */
        Animation animation;

        float64 dir;

    public:

        [[nodiscard]]
        RotarySaw() noexcept;

        /* ���������� */
        void Initialize() noexcept override;

        /* �X�V���� */
        void Update() noexcept override;

        /* �`�揈�� */
        void Render() const noexcept override;
    };
}
