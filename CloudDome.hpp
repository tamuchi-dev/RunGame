#pragma once
#include "Skydome.hpp"

namespace Game
{
    class CloudDome final : public Skydome
    {
    public:

        [[nodiscard]]
        CloudDome() noexcept;

        /* ���������� */
        void Initialize() noexcept override;
    };
}
