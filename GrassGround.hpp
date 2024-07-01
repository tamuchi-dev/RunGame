#pragma once
#include "Framework.hpp"

namespace Game
{
    class GrassGround final
    {
        /* �n�ʂ̒��� */
        const int32 length;

        /* �X�N���[�����x */
        const float64 scrollSpeed;

        /* ��ʊO�ɏo������X���W */
        const float64 outScreenX;
        
        /* �n�ʂ��q���ĕ`�悷�鎞�̂��炵�l */
        const Vector renderOffset;

        /* �����߂�����X���W */
        const float64 pushBackX;

        /* �摜 */
        Sprite sprite;

        /* �����̒n�ʂ̔z�u���W */
        Vector positionLhs;

        /* �E���̒n�ʂ̔z�u���W */
        Vector positionRhs;

    public:

        [[nodiscard]]
        GrassGround() noexcept;

        /* ���������� */
        void Initialize() noexcept;

        /* �X�V���� */
        void Update() noexcept;

        /* �`�揈�� */
        void Render() const noexcept;
    };
}
