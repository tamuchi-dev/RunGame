#include "ObjectDirector.hpp"
#include "Coin.hpp"

namespace Game
{
	void Coin::Initialize() noexcept
	{
		sprite.scale = 3;

		position = Vector{ 0, 0 };

		colider.Set(position);

		animation = Animation{ 0.1 };

		nowState = State::Inactive;
	}

	void Coin::Generate(float64 y) noexcept
	{
		Initialize();

		nowState = State::Active;
		position = Vector{ 2000, y };
	}

	void Coin::Delete() noexcept
	{
		Initialize();
	}

	void Coin::Update() noexcept
	{
		/* ��A�N�e�B�u�Ȃ珈������K�v������*/
		if (nowState == State::Inactive)
		{
			return;
		}

		const auto& icon = ObjectDirector::GetInstance().GetUIManager()->GetUI<CharaIcon>();

		switch (nowState)
		{
			case State::Active:
				position.x -= moveSpeed * FrameRate::GetDeltaTime();

				/* ��ʊO�ɏo����폜���� */
				if (position.x < outScreenX)
				{
					nowState = State::Inactive;
				}
				break;

			case State::Get:
				position = Vector::Lerp(position, icon->GetPosition(), 0.1);
				break;

			default:
				break;
		}

		colider.Set(position);

		animation.PlayLoop(sprite);
	}

	void Coin::Render() const noexcept
	{
		/* ��A�N�e�B�u�Ȃ珈������K�v������ */
		if (nowState == State::Inactive)
		{
			return;
		}

		sprite.Render(position, animation.GetNowAnimID());
	}
}