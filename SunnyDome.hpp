#pragma once
#include "Skydome.hpp"

namespace Game
{
    class SunnyDome final : public Skydome
    {
    public:

        [[nodiscard]]
        SunnyDome() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept override;
    };
}
