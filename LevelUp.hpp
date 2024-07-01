#pragma once
#include "Framework.hpp"

namespace Game
{
    class LevelUp final
    {
    public:

        enum class State
        {
            Active,

            Inactive,
        };

    private:

        /* 画像 */
        Sprite sprite;

        /* 配置座標 */
        Vector position;

        /* スクロール速度 */
        float64 scrollSpeed;

        /* 画面外に出た時のX座標 */
        float64 outScreenX;

        /* 現在の状態 */
        State nowState;

    public:

        [[nodiscard]]
        LevelUp() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept;

        /* 更新処理 */
        void Update() noexcept;

        /* 描画処理 */
        void Render() const noexcept;

        /* UIを動かすトリガー */
        void Trigger() noexcept;
    };
}
