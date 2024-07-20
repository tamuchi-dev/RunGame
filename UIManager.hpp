#pragma once
#include <tuple>
#include <memory>
#include "TitleLogo.hpp"
#include "PleaseLeftClick.hpp"
#include "Countdown.hpp"
#include "TimeLimit.hpp"
#include "CharaIcon.hpp"
#include "Score.hpp"
#include "LevelUp.hpp"
#include "Ranking.hpp"

namespace Game
{
    class UIManager final
    {
        // UIコンテナ
        std::tuple<
            std::unique_ptr<TitleLogo>,
            std::unique_ptr<PleaseLeftClick>,
            std::unique_ptr<Countdown>,
            std::unique_ptr<TimeLimit>,
            std::unique_ptr<CharaIcon>,
            std::unique_ptr<Score>,
            std::unique_ptr<LevelUp>,
            std::unique_ptr<Ranking>> container;

    public:

        [[nodiscard]]
        UIManager() noexcept;

        /* 指定したUIを取得する */
        template <class UIType>
        [[nodiscard]]
        UIType* GetUI() const noexcept
        {
            return std::get<std::unique_ptr<UIType>>(container).get();
        }
    };
}
