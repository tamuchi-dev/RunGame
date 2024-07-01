#pragma once
#include "BaseTypes.hpp"
#include "Vector.hpp"

namespace Game
{
    /* �L�[�R�[�h��� */
    enum class KeyCode
    {
        Return    = 0x1C,   /* �G���^�[�L�[ */
        Space     = 0x39,   /* �X�y�[�X�L�[ */
        BackSpace = 0x0E,   /* �o�b�N�X�y�[�X�L�[ */
        Tab       = 0x0F,   /* �^�u�L�[ */
        Escape    = 0x01,   /* �G�X�P�[�v�L�[ */

        ShiftL = 0x2A,      /* ���V�t�g�L�[ */
        ShiftR = 0x36,      /* �E�V�t�g�L�[ */
        CtrlL  = 0x1D,      /* ���R���g���[���L�[ */
        CtrlR  = 0x9D,      /* �E�R���g���[���L�[ */

        ArrowL = 0xCB,      /* �����L�[ */
        ArrowU = 0xC8,      /* ����L�[ */
        ArrowR = 0xCD,      /* �E���L�[ */
        ArrowD = 0xD0,      /* �����L�[ */

        _0 = 0x0B, _5 = 0x06,
        _1 = 0x02, _6 = 0x07,
        _2 = 0x03, _7 = 0x08,
        _3 = 0x04, _8 = 0x09,
        _4 = 0x05, _9 = 0x0A,

        A = 0x1E, J = 0x24, S = 0x1F,
        B = 0x30, K = 0x25, T = 0x14,
        C = 0x2E, L = 0x26, U = 0x16,
        D = 0x20, M = 0x32, V = 0x2F,
        E = 0x12, N = 0x31, W = 0x11,
        F = 0x21, O = 0x18, X = 0x2D,
        G = 0x22, P = 0x19, Y = 0x15,
        H = 0x23, Q = 0x10, Z = 0x2C,
        I = 0x17, R = 0x13,
    };

    /* �}�E�X�R�[�h��� */
    enum class MouseCode
    {
        ButtonL = 0x0001,   /* ���N���b�N�{�^�� */
        ButtonM = 0x0004,   /* �~�h���N���b�N�{�^�� */
        ButtonR = 0x0002,   /* �E�N���b�N�{�^�� */
    };

    class Input final
    {
        /* �L�[�̓��͏�� */
        static int32 keyState[256];

        /* �O�t���[���̃}�E�X���͏�� */
        static int32 oldMouseState;

        /* ���t���[���̃}�E�X���͏�� */
        static int32 nowMouseState;

        /* �}�E�X�J�[�\���̍��W */
        static Vector cursorPos;

    public:

        /* �X�V���� */
        static void Update() noexcept;

        /* �L�[���������u�Ԃ��H�𔻒肷�� */
        [[nodiscard]]
        static constexpr bool IsKeyDown(KeyCode keyCode) noexcept
        {
            return keyState[static_cast<int32>(keyCode)] == 1;
        }

        /* �L�[�������Ă��邩�H�𔻒肷�� */
        [[nodiscard]]
        static constexpr bool IsKeyHold(KeyCode keyCode) noexcept
        {
            return keyState[static_cast<int32>(keyCode)] >= 2;
        }

        /* �L�[�𗣂����u�Ԃ��H�𔻒肷�� */
        [[nodiscard]]
        static constexpr bool IsKeyUp(KeyCode keyCode) noexcept
        {
            return keyState[static_cast<int32>(keyCode)] == -1;
        }

        /* �}�E�X�{�^�����������u�Ԃ��H�𔻒肷�� */
        [[nodiscard]]
        static constexpr bool IsMouseButtonDown(MouseCode mouseCode) noexcept
        {
            const auto code = static_cast<int32>(mouseCode);

            return (nowMouseState & code) && not (oldMouseState & code);
        }

        /* �}�E�X�{�^���������Ă��邩�H�𔻒肷�� */
        [[nodiscard]]
        static constexpr bool IsMouseButtonHold(MouseCode mouseCode) noexcept
        {
            const auto code = static_cast<int32>(mouseCode);

            return (nowMouseState & code) && (oldMouseState & code);
        }

        /* �}�E�X�{�^���𗣂����u�Ԃ��H�𔻒肷�� */
        [[nodiscard]]
        static constexpr bool IsMouseButtonUp(MouseCode mouseCode) noexcept
        {
            const auto code = static_cast<int32>(mouseCode);

            return not (nowMouseState & code) && (oldMouseState & code);
        }

        /* �}�E�X�J�[�\���̍��W���擾���� */
        [[nodiscard]]
        static constexpr Vector GetCursorPos() noexcept
        {
            return cursorPos;
        }

    private:

        Input() = default;

        Input(const Input&) = delete;

        Input& operator=(const Input&) = delete;
    };
}
