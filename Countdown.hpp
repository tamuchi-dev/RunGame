#pragma once
#include "Framework.hpp"

namespace Game
{
    class Countdown final
    {
        /* �摜 */
        Sprite sprite;

        /* �z�u���W */
        Vector position;

        /* �o�߃f���^�^�C�� */
        float64 elapsedDelta;

        /* ���݂̃J�E���g�� */
        int32 nowCount;

    public:

        [[nodiscard]]
        Countdown() noexcept;

        /* ���������� */
        void Initialize() noexcept;

        /* �X�V���� */
        void Update() noexcept;

        /* �`�揈�� */
        void Render() const noexcept;

        /* �J�E���g�_�E�����I���������H�𔻒肷�� */
        [[nodiscard]]
        bool isEndCount() const noexcept
        {
            return nowCount == sprite.GetTotal();
        }
    };
}
