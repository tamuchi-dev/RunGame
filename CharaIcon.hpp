#pragma once
#include "Framework.hpp"

namespace Game
{
    class CharaIcon final
    {
        /* キャラアイコン画像 */
        Sprite iconSprite;

        /* フレーム画像 */
        Sprite frameSprite;

        /* キャラアイコンの配置座標 */
        Vector iconPos;

        /* フレームの配置座標 */
        Vector framePos;

    public:

        [[nodiscard]]
        CharaIcon() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept;

        /* 更新処理 */
        void Update() noexcept;

        /* 描画処理 */
        void Render() const noexcept;

        /* 配置座標を取得する */
        [[nodiscard]]
        constexpr const Vector& GetPosition() const noexcept
        {
            return framePos;
        }
    };
}
