#include <cmath>
#include "CircleColider.hpp"

namespace Game
{
    bool CircleColider::IsCollision(const CircleColider& lhs, const CircleColider& rhs) noexcept
    {
        const auto dx = lhs.x - rhs.x;
        const auto dy = lhs.y - rhs.y;

        return std::sqrt(dx * dx + dy * dy) <= lhs.r + rhs.r;
    }
}
