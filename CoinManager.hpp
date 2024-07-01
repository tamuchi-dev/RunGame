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
		/* �R�C���R���e�i */
		std::vector<std::unique_ptr<Coin>> container;

	public:

		[[nodiscard]]
		CoinManager() noexcept;

		/* ���������� */
		void Initialize() const noexcept;

		/* �X�V���� */
		void Update() const noexcept;

		/* �`�揈�� */
		void Render() const noexcept;

		/* �R�C���𐶐����� */
		template <class CoinType>
		void Generate(float64 y) const noexcept
		{
			/* �w�肵�������R�C���łȂ��Ȃ�A�T�[�g���� */
			static_assert
			(
				std::is_base_of<Coin, CoinType>::value,
				"�R�C���̎q�N���X���w�肵�Ă��������B"
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

		/* �R�C���R���e�i���擾���� */
		[[nodiscard]]
		constexpr const std::vector<std::unique_ptr<Coin>>& GetContainer() const noexcept
		{
			return container;
		}
	};
}