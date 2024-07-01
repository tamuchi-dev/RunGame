#pragma once
#include <memory>
#include "TitleScene.hpp"
#include "StageScene.hpp"
#include "ResultScene.hpp"
#include "CircleFade.hpp"

namespace Game
{
    class SceneDirector final
    {
        /* ���ݓ����Ă���V�[�� */
        std::unique_ptr<Scene> nowScene;

        std::unique_ptr<CircleFade> fade;

    public:

        /* �N������ */
        void Startup() noexcept;

        /* �Q�[�����I�����邩�H */
        [[nodiscard]]
        bool IsExitGame() const noexcept;

        /* �X�V���� */
        void Update() const noexcept;

        /* �`�揈�� */
        void Render() const noexcept;

        /* �V�[����؂�ւ��� */
        template <class SceneType>
        void ChangeScene() noexcept
        {
            /* �w�肵���^���V�[���łȂ��Ȃ�A�T�[�g���� */
            static_assert
            (
                std::is_base_of<Scene, SceneType>::value,
                "�V�[���̎q�N���X���w�肵�Ă��������B"
            );

            nowScene.reset();
            nowScene = std::make_unique<SceneType>();
            nowScene->Initialize();
        }

        /* ���̂��擾 */
        [[nodiscard]]
        static SceneDirector& GetInstance() noexcept
        {
            static SceneDirector instance;

            return instance;
        }

        CircleFade* GetFade() { return fade.get(); }

    private:

        SceneDirector() = default;

        SceneDirector(const SceneDirector&) = delete;

        SceneDirector& operator=(const SceneDirector&) = delete;
    };
}
