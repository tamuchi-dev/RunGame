#pragma once
#include "Framework.hpp"

namespace Game
{
    class Score final
    {
        /* �t���[���̉摜 */
        Sprite frameSprite;

        /* �X�R�A�̉摜 */
        Sprite scoreSprite;
        Sprite scoreSprite2;

        /* �R�C���A�C�R���̉摜 */
        Sprite coinIconSprite;

        Sprite coinSp;

        /* �t���[���̔z�u���W */
        Vector framePos;

        /* �X�R�A�̔z�u���W */
        Vector scorePos;

        /* �R�C���A�C�R���̔z�u���W*/
        Vector coinIconPos;

        /* ���オ�肵���ۂ̒����l */
        int32 carryOffsetX;

        int resultPoint;

        int resultUpPoint;

        int count;
        int inter;
        int speed;

    public:

        [[nodiscard]]
        Score() noexcept;

        /* ���������� */
        void Initialize() noexcept;

        /* �X�V���� */
        void Update() noexcept;

        void InResult();

        /* �`�揈�� */
        void Render() const noexcept;

        void ResultRender() const;
    };
}
