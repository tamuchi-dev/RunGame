#pragma once
#include "Framework.hpp"

namespace Game
{
    class Text
    {
    protected:

        /* �摜 */
        Sprite sprite;

        /* �z�u���W */
        Vector position;

    public:

        [[nodiscard]]
        Text() noexcept = default;

        virtual ~Text() noexcept = default;

        /* ���������� */
        virtual void Initialize() noexcept;

        /* �X�V���� */
        virtual void Update() noexcept;

        /* �`�揈�� */
        virtual void Render() const noexcept;
    };
}
