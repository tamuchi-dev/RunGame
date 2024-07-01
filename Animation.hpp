#pragma once
#include "BaseTypes.hpp"

namespace Game
{
    class Animation final
    {
        /* 時間をカウントする */
        float64 counter;

        /* 次のアニメーションに移行するときのインターバル */
        float64 interval;

        /* 現在のアニメーションID */
        int32 nowAnimID;

    public:

        [[nodiscard]]
        constexpr Animation() noexcept
        : counter{ 0 }
        , interval{ 0 }
        , nowAnimID{ 0 } {}

        [[nodiscard]]
        constexpr Animation(float64 interval) noexcept
        : counter{ 0 }
        , interval{ interval }
        , nowAnimID{ 0 } {}

        /* ループアニメーションをする */
        void PlayLoop(const class Sprite& sprite) noexcept;

        void PlayOnes(const class Sprite& sprite) noexcept;

        /* 現在のアニメーションIDを取得する */
        [[nodiscard]]
        constexpr int32 GetNowAnimID() const noexcept
        {
            return nowAnimID;
        }
    };
}
