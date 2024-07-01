#pragma once
#include "Framework.hpp"

namespace Game
{
    class Skydome
    {
    protected:

        /* 回転速度 */
        float64 rotationSpeed;

        /* 3Dモデル */
        Model model;

        /* 配置座標 */
        Vector position;

        /* 描画角度 */
        Vector angle;

    public:

        [[nodiscard]]
        Skydome() noexcept
        : rotationSpeed{ 0.05 } {}

        virtual ~Skydome() noexcept = default;

        /* 初期化処理 */
        virtual void Initialize() noexcept;

        /* 更新処理 */
        virtual void Update() noexcept;

        /* 描画処理 */
        virtual void Render() const noexcept;
    };
}
