#pragma once
#include <vector>
#include <memory>
#include "SunnyDome.hpp"
#include "NightDome.hpp"
#include "CloudDome.hpp"

namespace Game
{
    class SkydomeManager final
    {
        /* �X�J�C�h�[���R���e�i */
        std::vector<std::unique_ptr<Skydome>> container;

        /* ���݃A�N�e�B�u�ȃX�J�C�h�[�� */
        Skydome* nowSkydome;

    public:

        [[nodiscard]]
        SkydomeManager() noexcept;

        /* �X�V���� */
        void Update() const noexcept;

        /* �`�揈�� */
        void Render() const noexcept;

        /* �X�J�C�h�[����ύX���� */
        template <class SkydomeType>
        void ChangeSkydome() noexcept
        {
            /* �w�肵���^���X�J�C�h�[���łȂ��Ȃ�A�T�[�g���� */
            static_assert
                (
                    std::is_base_of<Skydome, SkydomeType>::value,
                    "�X�J�C�h�[���̎q�N���X���w�肵�Ă��������B"
                    );

            const auto iter = std::ranges::find_if(container, [](const auto& skydome)
                {
                    const auto& t1 = typeid(*skydome);
                    const auto& t2 = typeid(SkydomeType);

                    return t1 == t2;
                });

            if (iter != container.end())
            {
                nowSkydome = iter->get();
            }
        }
    };
}
