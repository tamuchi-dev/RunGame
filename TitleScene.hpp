#pragma once
#include "Scene.hpp"

namespace Game
{
    class TitleScene final : public Scene
    {
    public:

        /* ���������� */
        void Initialize() noexcept override;

        /* �Q�[�����I�����邩�H */
        [[nodiscard]]
        bool IsExitGame() const noexcept override;

        /* �V�[���J�ڏ��� */
        void Transition() const noexcept override;

        /* �X�V���� */
        void Update() noexcept override;

        /* �`�揈�� */
        void Render() const noexcept override;
    };
}
