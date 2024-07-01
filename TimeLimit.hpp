#pragma once
#include "Framework.hpp"

namespace Game
{
    class TimeLimit final
    {
        /* 画像 */
        Sprite sprite;

        /* 配置座標 */
        Vector position;

        /* 桁上がりした際の調整値 */
        int32 carryOffsetX;

    public:

        [[nodiscard]]
        TimeLimit() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept;

        /* 描画処理 */
        void Render() const noexcept;
    };
}
