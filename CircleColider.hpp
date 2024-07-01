#pragma once
#include "Vector.hpp"

namespace Game
{
    class CircleColider final
    {
        /* X座標 */
        float64 x;
        
        /* Y座標 */
        float64 y;

        /* 半径 */
        float64 r;

    public:

        friend class Debug;

        [[nodiscard]]
        constexpr CircleColider() noexcept
        : x{ 0 }
        , y{ 0 }
        , r{ 1 } {}

        [[nodiscard]]
        constexpr CircleColider(const CircleColider& colider) noexcept
        : x{ colider.x }
        , y{ colider.y }
        , r{ colider.r } {}

        [[nodiscard]]
        constexpr CircleColider(const Vector& position) noexcept
        : x{ position.x }
        , y{ position.y }
        , r{ 1 } {}

        [[nodiscard]]
        constexpr CircleColider(const Vector& position, float64 radius) noexcept
        : x{ position.x }
        , y{ position.y }
        , r{ radius } {}

        /* コライダの位置をセットする */
        constexpr void Set(const Vector& position) noexcept
        {
            x = position.x;
            y = position.y;
        }
        
        /* 円同士の当たり判定を行う */
        [[nodiscard]]
        static bool IsCollision(const CircleColider& lhs, const CircleColider& rhs) noexcept;

        /* 左のポイントを取得する */
        [[nodiscard]]
        constexpr float64 GetPointL() const noexcept
        {
            return x - r;
        }

        /* 上のポイントを取得する */
        [[nodiscard]]
        constexpr float64 GetPointU() const noexcept
        {
            return y - r;
        }

        /* 右のポイントを取得する */
        [[nodiscard]]
        constexpr float64 GetPointR() const noexcept
        {
            return x + r;
        }

        /* 下のポイントを取得する */
        [[nodiscard]]
        constexpr float64 GetPointD() const noexcept
        {
            return y + r;
        }
    };
}
