#pragma once
#include "Skydome.hpp"

namespace Game
{
    class NightDome final : public Skydome
    {
    public:

        [[nodiscard]]
        NightDome() noexcept;

        /* ���������� */
        void Initialize() noexcept override;
    };
}
