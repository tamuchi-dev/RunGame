#pragma once
#include <vector>
#include "BaseTypes.hpp"

namespace Game
{
    class Sprite final
    {
        /* 画像ハンドルコンテナ */
        std::vector<int32> handles;

    public:

        /* 画像の拡大率 */
        float64 scale;

        /* 画像の角度 */
        float64 angle;

        [[nodiscard]]
        constexpr Sprite() noexcept
        : scale{ 1 }
        , angle{ 0 } {}

        /* 画像を追加する */
        void Add(int32 handle) noexcept;

        /* 画像を描画する */
        void Render(const class Vector& position, bool isFlipX = false, bool isFlipY = false) const noexcept;

        /* インデックスを指定して画像を描画する */
        void Render(const class Vector& position, int32 index, bool isFlipX = false, bool isFlipY = false) const noexcept;

        /* 画像の総数を取得する */
        [[nodiscard]]
        constexpr int32 GetTotal() const noexcept
        {
            return static_cast<int32>(handles.size());
        }
    };
}
