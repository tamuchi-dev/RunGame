#pragma once
#include "Framework.hpp"

namespace Game
{
    class Obstacle
    {
    public:

        enum class State
        {
            Active,

            Inactive,
        };

    protected:

        /* �摜 */
        Sprite sprite;

        /* �z�u���W */
        Vector position;

        /* ��ʊO�̍��W */
        float64 outScreenX;

        /* �ړ����x */
        float64 moveSpeed;

        /* �����蔻�� */
        CircleColider colider;

        /* ���݂̏�� */
        State nowState;

    public:

        [[nodiscard]]
        constexpr Obstacle() noexcept
        : outScreenX{ -50 }
        , moveSpeed{ 600 }
        , nowState{ State::Inactive } {}

        virtual ~Obstacle() = default;

        /* ���������� */
        virtual void Initialize() noexcept;

        /* ��Q���𐶐����� */
        virtual void Generate() noexcept;

        /* �X�V���� */
        virtual void Update() noexcept;

        /* �`�揈�� */
        virtual void Render() const noexcept;

        /* �����蔻����擾���� */
        [[nodiscard]]
        constexpr const CircleColider& GetColider() const noexcept
        {
            return colider;
        }

        /* ���݂̏�Ԃ��擾���� */
        [[nodiscard]]
        constexpr State GetState() const noexcept
        {
            return nowState;
        }
    };
}
