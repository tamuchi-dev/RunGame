#pragma once
#include <vector>
#include <memory>
#include "RedCoin.hpp"
#include "GoldCoin.hpp"
#include "SilverCoin.hpp"

namespace Game
{
	class CoinManager final
	{
		/* コインコンテナ */
		std::vector<std::unique_ptr<Coin>> container;

	public:

		[[nodiscard]]
		CoinManager() noexcept;

		/* 初期化処理 */
		void Initialize() const noexcept;

		/* 更新処理 */
		void Update() const noexcept;

		/* 描画処理 */
		void Render() const noexcept;

		/* コインを生成する */
		template <class CoinType>
		void Generate(float64 y) const noexcept
		{
			/* 指定した方がコインでないならアサートする */
			static_assert
			(
				std::is_base_of<Coin, CoinType>::value,
				"コインの子クラスを指定してください。"
			);

			const auto iter = std::ranges::find_if(container, [](const auto& coin)
			{
				const auto& t1 = typeid(*coin);
				const auto& t2 = typeid(CoinType);

				return t1 == t2 && coin->GetState() == Coin::State::Inactive;
			});

			if (iter != container.end())
			{
				iter->get()->Generate(y);
			}
		}

		/* コインコンテナを取得する */
		[[nodiscard]]
		constexpr const std::vector<std::unique_ptr<Coin>>& GetContainer() const noexcept
		{
			return container;
		}
	};
}