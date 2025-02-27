#pragma once
#include "Skydome.hpp"

namespace Game
{
    class NightDome final : public Skydome
    {
    public:

        [[nodiscard]]
        NightDome() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept override;
    };
}
