#pragma once

namespace Game
{
	class TestGenerator final
	{
	public:

		/* �e�X�g�����s���� */
		static void Execute() noexcept;

	private:

		TestGenerator() = default;

		TestGenerator(const TestGenerator&) = delete;

		TestGenerator& operator=(const TestGenerator&) = delete;
	};
}