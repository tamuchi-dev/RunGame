#include <cmath>
#include "Vector.hpp"

namespace Game
{
    float64 Vector::Length() const noexcept
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector Vector::Normalize() const noexcept
    {
        const auto length = Length();

        if (length == 0.0)
        {
            return { 0.0, 0.0, 0.0 };
        }

        return { x / length, y / length, z / length };
    }

    float64 Vector::Distance(const Vector& lhs, const Vector& rhs) noexcept
    {
        const auto dx = lhs.x - rhs.x;
        const auto dy = lhs.y - rhs.y;
        const auto dz = lhs.z - rhs.z;

        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }
}
