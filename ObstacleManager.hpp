#pragma once
#include <vector>
#include <memory>
#include "GroundSpike.hpp"
#include "RotarySaw.hpp"
#include "SpikeBall.hpp"

namespace Game
{
    class ObstacleManager final
    {
        /* ��Q���R���e�i */
        std::vector<std::unique_ptr<Obstacle>> container;

    public:

        [[nodiscard]]
        ObstacleManager() noexcept;

        /* ���������� */
        void Initialize() const noexcept;

        /* �X�V���� */
        void Update() const noexcept;

        /* �`�揈�� */
        void Render() const noexcept;

        /* �������w�肵�ď�Q���𐶐����� */
        template <class ObstacleType>
        void Generate() const noexcept
        {
            /* �w�肵���^����Q���łȂ��Ȃ�A�T�[�g���� */
            static_assert
            (
                std::is_base_of<Obstacle, ObstacleType>::value,
                "��Q���̎q�N���X���w�肵�Ă��������B"
            );

            const auto iter = std::ranges::find_if(container, [](const auto& obstacle)
            {
                const auto& t1 = typeid(*obstacle);
                const auto& t2 = typeid(ObstacleType);

                return t1 == t2 && obstacle->GetState() == Obstacle::State::Inactive;
            });

            if (iter != container.end())
            {
                iter->get()->Generate();
            }
        }

        /* ��Q���R���e�i���擾���� */
        [[nodiscard]]
        constexpr const std::vector<std::unique_ptr<Obstacle>>& GetContainer() const noexcept
        {
            return container;
        }
    };
}
