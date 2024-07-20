#pragma once
#include "Framework.hpp"

namespace Game
{
    class Countdown final
    {
        static constexpr float64 scaleMax = 1.0;
        static constexpr float64 scaleMin = 0.3;
        static constexpr float64 rotaMax = 1.0;
        static constexpr float64 rotaMin = 0.0;
        static constexpr float64 speed = 0.01;
        static constexpr int32 intervalFrame = 30;

        /* �摜 */
        Sprite sprite;

        /* �z�u���W */
        Vector position;

        /* �o�߃f���^�^�C�� */
        float64 elapsedDelta;

        /* ���݂̃J�E���g�� */
        int32 nowCount;

        float64 scaleV = 0;
        float64 rotaV = 0;
        float64 bounds = 0.3;
        int SE1;
        bool is;
        int SE2;

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
