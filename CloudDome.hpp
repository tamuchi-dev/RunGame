#pragma once
#include "Skydome.hpp"

namespace Game
{
    class CloudDome final : public Skydome
    {
    public:

        [[nodiscard]]
        CloudDome() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept override;
    };
}
