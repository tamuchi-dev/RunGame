#pragma once
#include "BaseTypes.hpp"

namespace Game
{
    class Screen final
    {
    public:

        /* �X�N���[���̉��� */
        static int32 sizeX;
        
        /* �X�N���[���̏c�� */
        static int32 sizeY;

        /* �N������ */
        [[nodiscard]]
        static bool Startup() noexcept;

        /* �X�V���� */
        [[nodiscard]]
        static bool Update() noexcept;

        /* �I������ */
        static void Cleanup() noexcept;

        /* �X�N���[���̑傫����ݒ肷�� */
        static void SetSize(int32 x, int32 y) noexcept;

        /* �X�N���[���o�[�ɕ\������閼�O��ݒ肷�� */
        static void SetName(const char* name) noexcept;

    private:

        Screen() = default;

        Screen(const Screen&) = delete;

        Screen& operator=(const Screen&) = delete;
    };
}
