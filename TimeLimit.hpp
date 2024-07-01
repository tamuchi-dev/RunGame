#pragma once
#include "Framework.hpp"

namespace Game
{
    class TimeLimit final
    {
        /* �摜 */
        Sprite sprite;

        /* �z�u���W */
        Vector position;

        /* ���オ�肵���ۂ̒����l */
        int32 carryOffsetX;

    public:

        [[nodiscard]]
        TimeLimit() noexcept;

        /* ���������� */
        void Initialize() noexcept;

        /* �`�揈�� */
        void Render() const noexcept;
    };
}
