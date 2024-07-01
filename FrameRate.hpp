#pragma once
#include "BaseTypes.hpp"

namespace Game
{
    class FrameRate final
    {
        /* �O�t���[���̎��� */
        static int64 oldTime;

        /* ���t���[���̎��� */
        static int64 nowTime;

        /* �t���[���`�F�b�N���� */
        static int64 lastFrameCheckTime;

        /* �t���[���J�E���^ */
        static int32 frameCount;

        /* ���݂�FPS */
        static int32 nowFPS;

        /* �f���^�^�C�� */
        static float64 deltaTime;

        /* �v���O�������N�����Ă���̌o�ߎ��� */
        static int32 elapsedTime;

    public:

        /* �ݒ肵��FPS */
        static int32 targetFPS;

        friend class Debug;

        /* �N������ */
        static void Startup() noexcept;

        /* �X�V���� */
        static void Update() noexcept;

        /* �������������� */
        static void VSync() noexcept;

        /* �f���^�^�C�����擾���� */
        [[nodiscard]]
        static constexpr float64 GetDeltaTime() noexcept
        {
            return deltaTime;
        }

        /* �v���O�������N�����Ă���̌o�ߎ��Ԃ��擾���� */
        [[nodiscard]]
        static constexpr int32 GetElapsedTime() noexcept
        {
            return elapsedTime;
        }

    private:

        FrameRate() = default;

        FrameRate(const FrameRate&) = delete;

        FrameRate& operator=(const FrameRate&) = delete;
    };
}
