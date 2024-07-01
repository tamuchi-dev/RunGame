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
        /* スカイドームコンテナ */
        std::vector<std::unique_ptr<Skydome>> container;

        /* 現在アクティブなスカイドーム */
        Skydome* nowSkydome;

    public:

        [[nodiscard]]
        SkydomeManager() noexcept;

        /* 更新処理 */
        void Update() const noexcept;

        /* 描画処理 */
        void Render() const noexcept;

        /* スカイドームを変更する */
        template <class SkydomeType>
        void ChangeSkydome() noexcept
        {
            /* 指定した型がスカイドームでないならアサートする */
            static_assert
                (
                    std::is_base_of<Skydome, SkydomeType>::value,
                    "スカイドームの子クラスを指定してください。"
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
