#pragma once
#include "BaseTypes.hpp"

namespace Game
{
    class Animation final
    {
        /* ���Ԃ��J�E���g���� */
        float64 counter;

        /* ���̃A�j���[�V�����Ɉڍs����Ƃ��̃C���^�[�o�� */
        float64 interval;

        /* ���݂̃A�j���[�V����ID */
        int32 nowAnimID;

    public:

        [[nodiscard]]
        constexpr Animation() noexcept
        : counter{ 0 }
        , interval{ 0 }
        , nowAnimID{ 0 } {}

        [[nodiscard]]
        constexpr Animation(float64 interval) noexcept
        : counter{ 0 }
        , interval{ interval }
        , nowAnimID{ 0 } {}

        /* ���[�v�A�j���[�V���������� */
        void PlayLoop(const class Sprite& sprite) noexcept;

        void PlayOnes(const class Sprite& sprite) noexcept;

        /* ���݂̃A�j���[�V����ID���擾���� */
        [[nodiscard]]
        constexpr int32 GetNowAnimID() const noexcept
        {
            return nowAnimID;
        }
    };
}
