#pragma once
#include <array>
#include "Framework.hpp"

namespace Game
{
    class Ranking final
    {
        Sprite scoreSprite;

        Sprite frameSprite;

        std::array<int, 3> ranking;

        mutable int addAlphaValue;

        mutable int nowAlpha;

    public:

        [[nodiscard]]
        Ranking() noexcept;

        void Initialize() noexcept;

        void Update() noexcept;

        void Render() const noexcept;

        void LoadRanking() noexcept;

        void UpdateRanking() noexcept;

    private:

        void RenderScore(float x, float y, int score) const noexcept;
    };
}
