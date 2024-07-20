#pragma once
#include "Framework.hpp"

namespace Game
{
    class Countdown final
    {
        static constexpr float64 scaleMax = 1.0;
        static constexpr float64 scaleMin = 0.3;
        static constexpr float64 rotaMax = 1.0;
        static constexpr float64 rotaMin = 0.0;
        static constexpr float64 speed = 0.01;
        static constexpr int32 intervalFrame = 30;

        /* 画像 */
        Sprite sprite;

        /* 配置座標 */
        Vector position;

        /* 経過デルタタイム */
        float64 elapsedDelta;

        /* 現在のカウント数 */
        int32 nowCount;

        float64 scaleV = 0;
        float64 rotaV = 0;
        float64 bounds = 0.3;
        int SE1;
        bool is;
        int SE2;

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
