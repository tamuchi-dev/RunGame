#pragma once

namespace Game
{
	class TestGenerator final
	{
	public:

		/* テストを実行する */
		static void Execute() noexcept;

	private:

		TestGenerator() = default;

		TestGenerator(const TestGenerator&) = delete;

		TestGenerator& operator=(const TestGenerator&) = delete;
	};
}