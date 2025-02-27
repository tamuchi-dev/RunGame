#pragma once
#include "Framework.hpp"

namespace Game
{
    class TitleLogo final
    {
        /* 画像 */
        Sprite sprite;

        /* 配置座標 */
        Vector position;

    public:

        [[nodiscard]]
        TitleLogo() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept;

        /* 描画処理 */
        void Render() const noexcept;
    };
}
