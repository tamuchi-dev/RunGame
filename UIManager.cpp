#include "UIManager.hpp"

namespace Game
{
    UIManager::UIManager() noexcept
    {
        std::get<std::unique_ptr<TitleLogo>>(container)       = std::make_unique<TitleLogo>();
        std::get<std::unique_ptr<PleaseLeftClick>>(container) = std::make_unique<PleaseLeftClick>();
        std::get<std::unique_ptr<Countdown>>(container)       = std::make_unique<Countdown>();
        std::get<std::unique_ptr<TimeLimit>>(container)       = std::make_unique<TimeLimit>();
        std::get<std::unique_ptr<CharaIcon>>(container)       = std::make_unique<CharaIcon>();
        std::get<std::unique_ptr<Score>>(container)           = std::make_unique<Score>();
        std::get<std::unique_ptr<LevelUp>>(container)         = std::make_unique<LevelUp>();
    }
}
