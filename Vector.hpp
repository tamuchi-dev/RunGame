#pragma once
#include "BaseTypes.hpp"

namespace Game
{
    class Vector final
    {
    public:

        /* X���W */
        float64 x;

        /* Y���W */
        float64 y;

        /* Z���W */
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

        /* �������擾���� */
        [[nodiscard]]
        float64 Length() const noexcept;

        /* ������2����擾���� */
        [[nodiscard]]
        constexpr float64 LengthSq() const noexcept
        {
            return x * x + y * y + z * z;
        }

        /* ���K�������l���擾���� */
        [[nodiscard]]
        Vector Normalize() const noexcept;

        /* 2�̃x�N�g���̋������擾���� */
        [[nodiscard]]
        static float64 Distance(const Vector& lhs, const Vector& rhs) noexcept;

        /* 2�̃x�N�g���̋�����2����擾���� */
        [[nodiscard]]
        static constexpr float64 DistanceSq(const Vector& lhs, const Vector& rhs) noexcept
        {
            const auto dx = lhs.x - rhs.x;
            const auto dy = lhs.y - rhs.y;
            const auto dz = lhs.z - rhs.z;

            return dx * dx + dy * dy + dz * dz;
        }

        /* ���ς��擾���� */
        [[nodiscard]]
        static constexpr float64 Dot(const Vector& lhs, const Vector& rhs) noexcept
        {
            return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
        }

        /* �O�ς��擾���� */
        [[nodiscard]]
        static constexpr Vector Cross(const Vector& lhs, const Vector& rhs) noexcept
        {
            const auto dx = lhs.y * rhs.z - lhs.z * rhs.y;
            const auto dy = lhs.z * rhs.x - lhs.x * rhs.z;
            const auto dz = lhs.x * rhs.y - lhs.y * rhs.x;

            return { dx, dy, dz };
        }

        /* ���`�⊮�����x�N�g�����擾���� */
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
