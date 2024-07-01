#pragma once
#include "Framework.hpp"

namespace Game
{
    class TitleLogo final
    {
        /* �摜 */
        Sprite sprite;

        /* �z�u���W */
        Vector position;

    public:

        [[nodiscard]]
        TitleLogo() noexcept;

        /* ���������� */
        void Initialize() noexcept;

        /* �`�揈�� */
        void Render() const noexcept;
    };
}
