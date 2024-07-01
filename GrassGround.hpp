#pragma once
#include "Framework.hpp"

namespace Game
{
    class GrassGround final
    {
        /* 地面の長さ */
        const int32 length;

        /* スクロール速度 */
        const float64 scrollSpeed;

        /* 画面外に出た時のX座標 */
        const float64 outScreenX;
        
        /* 地面を繋げて描画する時のずらし値 */
        const Vector renderOffset;

        /* 押し戻す時のX座標 */
        const float64 pushBackX;

        /* 画像 */
        Sprite sprite;

        /* 左側の地面の配置座標 */
        Vector positionLhs;

        /* 右側の地面の配置座標 */
        Vector positionRhs;

    public:

        [[nodiscard]]
        GrassGround() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept;

        /* 更新処理 */
        void Update() noexcept;

        /* 描画処理 */
        void Render() const noexcept;
    };
}
