#pragma once
#include "Coin.hpp"

namespace Game
{
	class GoldCoin final : public Coin
	{
	public:

		[[nodiscard]]
		GoldCoin() noexcept;
	};
}