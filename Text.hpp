#pragma once
#include "Framework.hpp"

namespace Game
{
    class Text
    {
    protected:

        /* 画像 */
        Sprite sprite;

        /* 配置座標 */
        Vector position;

    public:

        [[nodiscard]]
        Text() noexcept = default;

        virtual ~Text() noexcept = default;

        /* 初期化処理 */
        virtual void Initialize() noexcept;

        /* 更新処理 */
        virtual void Update() noexcept;

        /* 描画処理 */
        virtual void Render() const noexcept;
    };
}
