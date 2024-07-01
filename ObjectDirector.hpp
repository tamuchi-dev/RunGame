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
        /* �v���C�� */
        std::unique_ptr<NinjaFrog> player;

        /* ��Q���}�l�[�W�� */
        std::unique_ptr<ObstacleManager> obstacleManager;

        /* �R�C���}�l�[�W�� */
        std::unique_ptr<CoinManager> coinManager;

        /* �n�� */
        std::unique_ptr<GrassGround> ground;

        /* �X�J�C�h�[���}�l�[�W�� */
        std::unique_ptr<SkydomeManager> skydomeManager;

        /* UI�}�l�[�W�� */
        std::unique_ptr<UIManager> uiManager;

    public:

        /* �N������ */
        void Startup() noexcept;

        /* �v���C�����擾���� */
        [[nodiscard]]
        NinjaFrog* GetPlayer() const noexcept
        {
            return player.get();
        }

        /* ��Q���}�l�[�W�����擾���� */
        [[nodiscard]]
        ObstacleManager* GetObstacleManager() const noexcept
        {
            return obstacleManager.get();
        }

        /* �R�C���}�l�[�W�����擾���� */
        [[nodiscard]]
        CoinManager* GetCoinManager() const noexcept
        {
            return coinManager.get();
        }

        /* �n�ʂ��擾���� */
        [[nodiscard]]
        GrassGround* GetGround() const noexcept
        {
            return ground.get();
        }

        /* �X�J�C�h�[���}�l�[�W�����擾���� */
        [[nodiscard]]
        SkydomeManager* GetSkydomeManager() const noexcept
        {
            return skydomeManager.get();
        }

        /* UI�}�l�[�W�����擾���� */
        [[nodiscard]]
        UIManager* GetUIManager() const noexcept
        {
            return uiManager.get();
        }

        /* ���̂��擾���� */
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
