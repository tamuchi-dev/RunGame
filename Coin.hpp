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

		/* �摜 */
		Sprite sprite;

		/* �A�j���[�V���� */
		Animation animation;

		/* �z�u���W */
		Vector position;

		/* ��ʊO�̍��W */
		float64 outScreenX;

		/* �ړ����x */
		float64 moveSpeed;

		/* �l���ł���X�R�A�� */
		int32 acquisitionScore;

		/* �����蔻�� */
		CircleColider colider;

		/* ���݂̏�� */
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

		/* ���������� */
		virtual void Initialize() noexcept;

		/* �R�C���������� */
		virtual void Generate(float64 y) noexcept;

		/* �R�C������������ */
		virtual void Delete() noexcept;

		/* �X�V���� */
		virtual void Update() noexcept;

		/* �`�揈�� */
		virtual void Render() const noexcept;

		/* �R�C�����l������ */
		constexpr void GetCoin() noexcept
		{
			nowState = State::Get;
		}

		/* �����蔻����擾���� */
		[[nodiscard]]
		constexpr const CircleColider& GetColider() const noexcept
		{
			return colider;
		}

		/* ���W���擾���� */
		[[nodiscard]]
		constexpr const Vector& GetPosition() const noexcept
		{
			return position;
		}

		/* ���݂̏�Ԃ��擾���� */
		[[nodiscard]]
		constexpr State GetState() const noexcept
		{
			return nowState;
		}

		/* �l���ł���X�R�A�ʂ��擾���� */
		[[nodiscard]]
		constexpr int32 GetAcquisitionScore() const noexcept
		{
			return acquisitionScore;
		}
	};
}