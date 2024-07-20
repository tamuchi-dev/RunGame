#pragma once
#include "Framework.hpp"

namespace Game
{
    class NinjaFrog final
    {
        /* ジャンプ力 */
        const float64 jumpForce;

        /* 落下速度 */
        const float64 fallSpeed;

        /* 地面のY座標 */
        const float64 groundY;

        /* 最大ジャンプ回数 */
        const int32 jumpCountMax;

        /* 画像 */
        Sprite sprite;

        Sprite jumpSprite;

        Sprite fallSprite;

        Sprite deadSprite;

        Sprite idleSprite;

        /* アニメーション */
        Animation animation;

        Animation idleAnim;

        Animation deadAnim;

        /* 配置座標 */
        Vector position;

        /* 当たり判定 */
        CircleColider colider;

        /* 上下の移動ベクトル */
        float64 vectorY;

        /* 現在のジャンプ回数 */
        int32 jumpCount;
        
        bool isDead;

        int dieSE;
        bool dieSEFlg;
        int jumpSE;
        bool jumpSEFlg;

        float64 deadInterval;

    public:

        [[nodiscard]]
        NinjaFrog() noexcept;

        /* 初期化処理 */
        void Initialize() noexcept;

        /* 更新処理 */
        void Update() noexcept;

        void OverUpdate();

        void ClearUpdate();

        /* 死亡処理 */
        void Dead() noexcept;

        /* 描画処理 */
        void Render() const noexcept;

        void OverRender();

        /* 当たり判定を取得する */
        [[nodiscard]]
        constexpr const CircleColider& GetColider() const noexcept
        {
            return colider;
        }

        [[nodiscard]]
        bool IsEndDead() { return deadInterval == 0; }
    };
}
