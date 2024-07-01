#include "CoinManager.hpp"

namespace Game
{
	CoinManager::CoinManager() noexcept
	{
		/* ‘S‚Ä‚ÌƒRƒCƒ“‚ð100ŒÂ‚¸‚Â’Ç‰Á */
		for (int i = 0; i < 100; ++i)
		{
			container.emplace_back(std::make_unique<RedCoin>());
			container.emplace_back(std::make_unique<GoldCoin>());
			container.emplace_back(std::make_unique<SilverCoin>());
		}
	}

	void CoinManager::Initialize() const noexcept
	{
		for (const auto& coin : container)
		{
			coin->Initialize();
		}
	}

	void CoinManager::Update() const noexcept
	{
		for (const auto& coin : container)
		{
			coin->Update();
		}
	}

	void CoinManager::Render() const noexcept
	{
		for (const auto& coin : container)
		{
			coin->Render();
		}
	}
}