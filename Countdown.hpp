#pragma once
#include "Framework.hpp"

namespace Game
{
    class Countdown final
    {
        /* 画像 */
        Sprite sprite;

        /* 配置座標 */
        Vector position;

        /* 経過デルタタイム */
        float64 elapsedDelta;

        /* 現在のカウント数 */
        int32 nowCount;

    public:

        [[nodiscard]]
        Countdown() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept;

        /* 更新処理 */
        void Update() noexcept;

        /* 描画処理 */
        void Render() const noexcept;

        /* カウントダウンが終了したか？を判定する */
        [[nodiscard]]
        bool isEndCount() const noexcept
        {
            return nowCount == sprite.GetTotal();
        }
    };
}
