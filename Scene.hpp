#pragma once

namespace Game
{
    class Scene
    {
    protected:

        Scene() = default;

    public:

        virtual ~Scene() noexcept = default;

        /* ���������� */
        virtual void Initialize() noexcept;

        /* �Q�[�����I�����邩�H */
        [[nodiscard]]
        virtual bool IsExitGame() const noexcept;

        /* �V�[���J�ڏ��� */
        virtual void Transition() const noexcept = 0;

        /* �X�V���� */
        virtual void Update() noexcept = 0;

        /* �`�揈�� */
        virtual void Render() const noexcept = 0;

        Scene(const Scene&) = delete;

        Scene& operator=(const Scene&) = delete;
    };
}
