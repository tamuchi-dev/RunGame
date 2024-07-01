#pragma once
#include <vector>
#include <memory>
#include "NinjaFrog.hpp"
#include "ObstacleManager.hpp"
#include "CoinManager.hpp"
#include "GrassGround.hpp"
#include "SkydomeManager.hpp"
#include "UIManager.hpp"

namespace Game
{
    class ObjectDirector final
    {
        /* プレイヤ */
        std::unique_ptr<NinjaFrog> player;

        /* 障害物マネージャ */
        std::unique_ptr<ObstacleManager> obstacleManager;

        /* コインマネージャ */
        std::unique_ptr<CoinManager> coinManager;

        /* 地面 */
        std::unique_ptr<GrassGround> ground;

        /* スカイドームマネージャ */
        std::unique_ptr<SkydomeManager> skydomeManager;

        /* UIマネージャ */
        std::unique_ptr<UIManager> uiManager;

    public:

        /* 起動準備 */
        void Startup() noexcept;

        /* プレイヤを取得する */
        [[nodiscard]]
        NinjaFrog* GetPlayer() const noexcept
        {
            return player.get();
        }

        /* 障害物マネージャを取得する */
        [[nodiscard]]
        ObstacleManager* GetObstacleManager() const noexcept
        {
            return obstacleManager.get();
        }

        /* コインマネージャを取得する */
        [[nodiscard]]
        CoinManager* GetCoinManager() const noexcept
        {
            return coinManager.get();
        }

        /* 地面を取得する */
        [[nodiscard]]
        GrassGround* GetGround() const noexcept
        {
            return ground.get();
        }

        /* スカイドームマネージャを取得する */
        [[nodiscard]]
        SkydomeManager* GetSkydomeManager() const noexcept
        {
            return skydomeManager.get();
        }

        /* UIマネージャを取得する */
        [[nodiscard]]
        UIManager* GetUIManager() const noexcept
        {
            return uiManager.get();
        }

        /* 実体を取得する */
        [[nodiscard]]
        static ObjectDirector& GetInstance() noexcept
        {
            static ObjectDirector instance;

            return instance;
        }

    private:

        ObjectDirector() = default;

        ObjectDirector(const ObjectDirector&) = default;

        ObjectDirector& operator=(const ObjectDirector&) = default;
    };
}
