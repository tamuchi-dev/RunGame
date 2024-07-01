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
        /* 障害物コンテナ */
        std::vector<std::unique_ptr<Obstacle>> container;

    public:

        [[nodiscard]]
        ObstacleManager() noexcept;

        /* 初期化処理 */
        void Initialize() const noexcept;

        /* 更新処理 */
        void Update() const noexcept;

        /* 描画処理 */
        void Render() const noexcept;

        /* 方向を指定して障害物を生成する */
        template <class ObstacleType>
        void Generate() const noexcept
        {
            /* 指定した型が障害物でないならアサートする */
            static_assert
            (
                std::is_base_of<Obstacle, ObstacleType>::value,
                "障害物の子クラスを指定してください。"
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

        /* 障害物コンテナを取得する */
        [[nodiscard]]
        constexpr const std::vector<std::unique_ptr<Obstacle>>& GetContainer() const noexcept
        {
            return container;
        }
    };
}
