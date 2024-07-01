#pragma once
#include "Framework.hpp"

namespace Game
{
    class Obstacle
    {
    public:

        enum class State
        {
            Active,

            Inactive,
        };

    protected:

        /* 画像 */
        Sprite sprite;

        /* 配置座標 */
        Vector position;

        /* 画面外の座標 */
        float64 outScreenX;

        /* 移動速度 */
        float64 moveSpeed;

        /* 当たり判定 */
        CircleColider colider;

        /* 現在の状態 */
        State nowState;

    public:

        [[nodiscard]]
        constexpr Obstacle() noexcept
        : outScreenX{ -50 }
        , moveSpeed{ 600 }
        , nowState{ State::Inactive } {}

        virtual ~Obstacle() = default;

        /* 初期化処理 */
        virtual void Initialize() noexcept;

        /* 障害物を生成する */
        virtual void Generate() noexcept;

        /* 更新処理 */
        virtual void Update() noexcept;

        /* 描画処理 */
        virtual void Render() const noexcept;

        /* 当たり判定を取得する */
        [[nodiscard]]
        constexpr const CircleColider& GetColider() const noexcept
        {
            return colider;
        }

        /* 現在の状態を取得する */
        [[nodiscard]]
        constexpr State GetState() const noexcept
        {
            return nowState;
        }
    };
}
