#pragma once
#include "Skydome.hpp"

namespace Game
{
    class SunnyDome final : public Skydome
    {
    public:

        [[nodiscard]]
        SunnyDome() noexcept;

        /* ���������� */
        void Initialize() noexcept override;
    };
}
