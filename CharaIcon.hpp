#pragma once
#include "Framework.hpp"

namespace Game
{
    class CharaIcon final
    {
        /* �L�����A�C�R���摜 */
        Sprite iconSprite;

        /* �t���[���摜 */
        Sprite frameSprite;

        /* �L�����A�C�R���̔z�u���W */
        Vector iconPos;

        /* �t���[���̔z�u���W */
        Vector framePos;

    public:

        [[nodiscard]]
        CharaIcon() noexcept;

        /* ���������� */
        void Initialize() noexcept;

        /* �X�V���� */
        void Update() noexcept;

        /* �`�揈�� */
        void Render() const noexcept;

        /* �z�u���W���擾���� */
        [[nodiscard]]
        constexpr const Vector& GetPosition() const noexcept
        {
            return framePos;
        }
    };
}
