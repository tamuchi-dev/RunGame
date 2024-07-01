#pragma once
#include "BaseTypes.hpp"

namespace Game
{
    class Vector final
    {
    public:

        /* X座標 */
        float64 x;

        /* Y座標 */
        float64 y;

        /* Z座標 */
        float64 z;

        [[nodiscard]]
        constexpr Vector() noexcept
        : x{ 0 }
        , y{ 0 }
        , z{ 0 } {}

        [[nodiscard]]
        constexpr Vector(const Vector& initValue) noexcept
        : x{ initValue.x }
        , y{ initValue.y }
        , z{ initValue.z } {}

        [[nodiscard]]
        constexpr Vector(float64 x, float64 y) noexcept
        : x{ x }
        , y{ y }
        , z{ 0 } {}

        [[nodiscard]]
        constexpr Vector(float64 x, float64 y, float64 z) noexcept
        : x{ x }
        , y{ y }
        , z{ z } {}

        /* 長さを取得する */
        [[nodiscard]]
        float64 Length() const noexcept;

        /* 長さの2乗を取得する */
        [[nodiscard]]
        constexpr float64 LengthSq() const noexcept
        {
            return x * x + y * y + z * z;
        }

        /* 正規化した値を取得する */
        [[nodiscard]]
        Vector Normalize() const noexcept;

        /* 2つのベクトルの距離を取得する */
        [[nodiscard]]
        static float64 Distance(const Vector& lhs, const Vector& rhs) noexcept;

        /* 2つのベクトルの距離の2乗を取得する */
        [[nodiscard]]
        static constexpr float64 DistanceSq(const Vector& lhs, const Vector& rhs) noexcept
        {
            const auto dx = lhs.x - rhs.x;
            const auto dy = lhs.y - rhs.y;
            const auto dz = lhs.z - rhs.z;

            return dx * dx + dy * dy + dz * dz;
        }

        /* 内積を取得する */
        [[nodiscard]]
        static constexpr float64 Dot(const Vector& lhs, const Vector& rhs) noexcept
        {
            return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
        }

        /* 外積を取得する */
        [[nodiscard]]
        static constexpr Vector Cross(const Vector& lhs, const Vector& rhs) noexcept
        {
            const auto dx = lhs.y * rhs.z - lhs.z * rhs.y;
            const auto dy = lhs.z * rhs.x - lhs.x * rhs.z;
            const auto dz = lhs.x * rhs.y - lhs.y * rhs.x;

            return { dx, dy, dz };
        }

        /* 線形補完したベクトルを取得する */
        [[nodiscard]]
        static constexpr Vector Lerp(const Vector& lhs, const Vector& rhs, float64 t) noexcept
        {
            return lhs + ((rhs - lhs) * t);
        }

        [[nodiscard]]
        constexpr Vector operator+(const Vector& other) const noexcept
        {
            return { x + other.x, y + other.y, z + other.z };
        }

        [[nodiscard]]
        constexpr Vector operator-(const Vector& other) const noexcept
        {
            return { x - other.x, y - other.y, z - other.z };
        }

        [[nodiscard]]
        constexpr Vector operator*(const Vector& other) const noexcept
        {
            return { x * other.x, y * other.y, z * other.z };
        }

        [[nodiscard]]
        constexpr Vector operator*(float64 scale) const noexcept
        {
            return { x * scale, y * scale, z * scale };
        }

        [[nodiscard]]
        constexpr Vector operator/(const Vector& other) const noexcept
        {
            return { x / other.x, y / other.y, z / other.z };
        }

        [[nodiscard]]
        constexpr Vector operator/(float64 scale) const noexcept
        {
            return { x / scale, y / scale, z / scale };
        }

        constexpr void operator+=(const Vector& other) noexcept
        {
            x += other.x;
            y += other.y;
            z += other.z;
        }

        constexpr void operator-=(const Vector& other) noexcept
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
        }

        constexpr void operator*=(const Vector& other) noexcept
        {
            x *= other.x;
            y *= other.y;
            z *= other.z;
        }

        constexpr void operator*=(float64 scale) noexcept
        {
            x *= scale;
            y *= scale;
            z *= scale;
        }

        constexpr void operator/=(const Vector& other) noexcept
        {
            x /= other.x;
            y /= other.y;
            z /= other.z;
        }

        constexpr void operator/=(float64 scale) noexcept
        {
            x /= scale;
            y /= scale;
            z /= scale;
        }

        [[nodiscard]]
        constexpr bool operator==(const Vector& other) const noexcept
        {
            return (x == other.x) && (y == other.y) && (z == other.z);
        }

        [[nodiscard]]
        constexpr bool operator!=(const Vector& other) const noexcept
        {
            return (x != other.x) || (y != other.y) || (z != other.z);
        }
    };
}
