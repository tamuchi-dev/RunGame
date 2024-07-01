#include "ObjectDirector.hpp"

namespace Game
{
    void ObjectDirector::Startup() noexcept
    {
        player          = std::make_unique<NinjaFrog>();
        obstacleManager = std::make_unique<ObstacleManager>();
        coinManager     = std::make_unique<CoinManager>();
        ground          = std::make_unique<GrassGround>();
        skydomeManager  = std::make_unique<SkydomeManager>();
        uiManager       = std::make_unique<UIManager>();
    }
}
