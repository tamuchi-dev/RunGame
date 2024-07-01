#pragma once
#include "Skydome.hpp"

namespace Game
{
    class CloudDome final : public Skydome
    {
    public:

        [[nodiscard]]
        CloudDome() noexcept;

        /* ‰Šú‰»ˆ— */
        void Initialize() noexcept override;
    };
}
