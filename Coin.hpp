#pragma once
#include "Framework.hpp"

namespace Game
{
	class Coin
	{
	public:

		enum class State
		{
			Active,

			Get,

			Inactive,
		};

	protected:

		/* 画像 */
		Sprite sprite;

		/* アニメーション */
		Animation animation;

		/* 配置座標 */
		Vector position;

		/* 画面外の座標 */
		float64 outScreenX;

		/* 移動速度 */
		float64 moveSpeed;

		/* 獲得できるスコア数 */
		int32 acquisitionScore;

		/* 当たり判定 */
		CircleColider colider;

		/* 現在の状態 */
		State nowState;

	public:

		[[nodiscard]]
        constexpr Coin() noexcept
            : outScreenX{ -30 }
            , moveSpeed{ 600 }
            , colider{ position, 20 }
            , acquisitionScore{ 0 }
            , nowState{ State::Inactive } {}


		virtual ~Coin() noexcept = default;

		/* 初期化処理 */
		virtual void Initialize() noexcept;

		/* コイン生成処理 */
		virtual void Generate(float64 y) noexcept;

		/* コインを消去する */
		virtual void Delete() noexcept;

		/* 更新処理 */
		virtual void Update() noexcept;

		/* 描画処理 */
		virtual void Render() const noexcept;

		/* コインを獲得する */
		constexpr void GetCoin() noexcept
		{
			nowState = State::Get;
		}

		/* 当たり判定を取得する */
		[[nodiscard]]
		constexpr const CircleColider& GetColider() const noexcept
		{
			return colider;
		}

		/* 座標を取得する */
		[[nodiscard]]
		constexpr const Vector& GetPosition() const noexcept
		{
			return position;
		}

		/* 現在の状態を取得する */
		[[nodiscard]]
		constexpr State GetState() const noexcept
		{
			return nowState;
		}

		/* 獲得できるスコア量を取得する */
		[[nodiscard]]
		constexpr int32 GetAcquisitionScore() const noexcept
		{
			return acquisitionScore;
		}
	};
}