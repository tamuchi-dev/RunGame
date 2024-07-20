#pragma once
#include "Framework.hpp"

namespace Game
{
    class Score final
    {
        /* フレームの画像 */
        Sprite frameSprite;

        /* スコアの画像 */
        Sprite scoreSprite;
        Sprite scoreSprite2;

        /* コインアイコンの画像 */
        Sprite coinIconSprite;

        Sprite coinSp;

        /* フレームの配置座標 */
        Vector framePos;

        /* スコアの配置座標 */
        Vector scorePos;

        /* コインアイコンの配置座標*/
        Vector coinIconPos;

        /* 桁上がりした際の調整値 */
        int32 carryOffsetX;

        int resultPoint;

        int resultUpPoint;

        int count;
        int inter;
        int speed;

    public:

        [[nodiscard]]
        Score() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept;

        /* 更新処理 */
        void Update() noexcept;

        void InResult();

        /* 描画処理 */
        void Render() const noexcept;

        void ResultRender() const;
    };
}
