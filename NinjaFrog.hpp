#pragma once
#include "Framework.hpp"

namespace Game
{
    class NinjaFrog final
    {
        /* �W�����v�� */
        const float64 jumpForce;

        /* �������x */
        const float64 fallSpeed;

        /* �n�ʂ�Y���W */
        const float64 groundY;

        /* �ő�W�����v�� */
        const int32 jumpCountMax;

        /* �摜 */
        Sprite sprite;

        Sprite jumpSprite;

        Sprite fallSprite;

        Sprite deadSprite;

        Sprite idleSprite;

        /* �A�j���[�V���� */
        Animation animation;

        Animation idleAnim;

        Animation deadAnim;

        /* �z�u���W */
        Vector position;

        /* �����蔻�� */
        CircleColider colider;

        /* �㉺�̈ړ��x�N�g�� */
        float64 vectorY;

        /* ���݂̃W�����v�� */
        int32 jumpCount;
        
        bool isDead;

        int dieSE;
        bool dieSEFlg;
        int jumpSE;
        bool jumpSEFlg;

        float64 deadInterval;

    public:

        [[nodiscard]]
        NinjaFrog() noexcept;

        /* ���������� */
        void Initialize() noexcept;

        /* �X�V���� */
        void Update() noexcept;

        void OverUpdate();

        void ClearUpdate();

        /* ���S���� */
        void Dead() noexcept;

        /* �`�揈�� */
        void Render() const noexcept;

        void OverRender();

        /* �����蔻����擾���� */
        [[nodiscard]]
        constexpr const CircleColider& GetColider() const noexcept
        {
            return colider;
        }

        [[nodiscard]]
        bool IsEndDead() { return deadInterval == 0; }
    };
}
