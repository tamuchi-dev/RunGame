#pragma once
#include "Scene.hpp"

namespace Game
{
    class StageScene final : public Scene
    {
        enum class State
        {
            /* �J�E���g�_�E���� */
            Coutdown,

            /* �Q�[���� */
            NowGame,

            GameOver,
        };

        /* ���݂̏�� */
        State nowState;

    public:

        /* ���������� */
        void Initialize() noexcept override;

        /* �V�[���J�ڏ��� */
        void Transition() const noexcept override;

        /* �X�V���� */
        void Update() noexcept override;

        /* �`�揈�� */
        void Render() const noexcept override;
    };
}
