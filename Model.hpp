#pragma once
#include "BaseTypes.hpp"

namespace Game
{
    class Model final
    {
        /* ���f���n���h�� */
        int32 model;

    public:

        [[nodiscard]]
        constexpr Model() noexcept
        : model{ 0 } {}

        /* ���f���n���h�����Z�b�g���� */
        constexpr void Set(int32 handle) noexcept
        {
            model = handle;
        }

        /* ���W���w�肵�ĕ`�悷�� */
        void Render(const class Vector& position) const noexcept;

        /* ���W�Ɗp�x���w�肵�ĕ`�悷�� */
        void Render(const class Vector& position, const class Vector& angle) const noexcept;
    };
}
