#pragma once
#include "BaseTypes.hpp"

namespace Game
{
    class Debug final
    {
        /* �f�o�b�O���L�����H */
        static bool isEnable;

    public:

        /* �f�o�b�O��L���ɂ��� */
        static void Enable() noexcept;

        /* �f�o�b�O�𖳌��ɂ��� */
        static void Disable() noexcept;

        /* ���W���w�肵�ăf�o�b�O�\�������� */
        static void Log(int32 x, int32 y, const char* format, ...) noexcept;

        /* �G���[���b�Z�[�W�{�b�N�X��\�� */
        static void ErrorMessageBox(const char* message) noexcept;

        /* �R���C�_��\������ */
        static void Render(const class CircleColider& colider) noexcept;

        /* �t���[�����[�g����\������ */
        static void FrameRate() noexcept;

        /* 2D�̊�������� */
        static void BaseLine2D() noexcept;

    private:

        Debug() = default;

        Debug(const Debug&) = delete;

        Debug& operator=(const Debug&) = delete;
    };
}
