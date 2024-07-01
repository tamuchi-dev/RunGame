#include "SkydomeManager.hpp"

namespace Game
{
    SkydomeManager::SkydomeManager() noexcept
    {
        container.emplace_back(std::make_unique<SunnyDome>());
        container.emplace_back(std::make_unique<NightDome>());
        container.emplace_back(std::make_unique<CloudDome>());

        ChangeSkydome<SunnyDome>();
    }
    
    void SkydomeManager::Update() const noexcept
    {
        nowSkydome->Update();
    }

    void SkydomeManager::Render() const noexcept
    {
        nowSkydome->Render();
    }
}
