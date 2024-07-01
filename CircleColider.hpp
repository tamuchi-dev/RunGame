#pragma once
#include "Vector.hpp"

namespace Game
{
    class CircleColider final
    {
        /* X���W */
        float64 x;
        
        /* Y���W */
        float64 y;

        /* ���a */
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

        /* �R���C�_�̈ʒu���Z�b�g���� */
        constexpr void Set(const Vector& position) noexcept
        {
            x = position.x;
            y = position.y;
        }
        
        /* �~���m�̓����蔻����s�� */
        [[nodiscard]]
        static bool IsCollision(const CircleColider& lhs, const CircleColider& rhs) noexcept;

        /* ���̃|�C���g���擾���� */
        [[nodiscard]]
        constexpr float64 GetPointL() const noexcept
        {
            return x - r;
        }

        /* ��̃|�C���g���擾���� */
        [[nodiscard]]
        constexpr float64 GetPointU() const noexcept
        {
            return y - r;
        }

        /* �E�̃|�C���g���擾���� */
        [[nodiscard]]
        constexpr float64 GetPointR() const noexcept
        {
            return x + r;
        }

        /* ���̃|�C���g���擾���� */
        [[nodiscard]]
        constexpr float64 GetPointD() const noexcept
        {
            return y + r;
        }
    };
}
