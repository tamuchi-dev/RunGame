#pragma once
#include "BaseTypes.hpp"

namespace Game
{
    class Model final
    {
        /* モデルハンドル */
        int32 model;

    public:

        [[nodiscard]]
        constexpr Model() noexcept
        : model{ 0 } {}

        /* モデルハンドルをセットする */
        constexpr void Set(int32 handle) noexcept
        {
            model = handle;
        }

        /* 座標を指定して描画する */
        void Render(const class Vector& position) const noexcept;

        /* 座標と角度を指定して描画する */
        void Render(const class Vector& position, const class Vector& angle) const noexcept;
    };
}
