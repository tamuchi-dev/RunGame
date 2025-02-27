#include "ObstacleManager.hpp"

namespace Game
{
    ObstacleManager::ObstacleManager() noexcept
    {
        /* 全ての障害物を20個ずつ追加 */
        for (int i = 0; i < 20; ++i)
        {
            container.emplace_back(std::make_unique<GroundSpike>());
            container.emplace_back(std::make_unique<RotarySaw>());
            container.emplace_back(std::make_unique<SpikeBall>());
        }
    }

    void ObstacleManager::Initialize() const noexcept
    {
        for (const auto& obstacle : container)
        {
            obstacle->Initialize();
        }
    }

    void ObstacleManager::Update() const noexcept
    {
        for (const auto& obstacle : container)
        {
            obstacle->Update();
        }
    }

    void ObstacleManager::Render() const noexcept
    {
        for (const auto& obstacle : container)
        {
            obstacle->Render();
        }
    }
}
