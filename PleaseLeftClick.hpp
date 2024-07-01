#pragma once
#include "Framework.hpp"

namespace Game
{
    class PleaseLeftClick final
    {
        /* 画像 */
        Sprite sprite;

        /* 配置座標 */
        Vector position;

        /* 透明度を変化させる量 */
        int32 addAlphaValue;

        /* 現在の透明度 */
        int32 nowAlpha;

    public:

        [[nodiscard]]
        PleaseLeftClick() noexcept;
        
        /* 初期化処理 */
        void Initialize() noexcept;

        /* 更新処理 */
        void Update() noexcept;

        /* 描画処理 */
        void Render() const noexcept;
    };
}
