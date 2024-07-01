#pragma once

namespace Game
{
    class Scene
    {
    protected:

        Scene() = default;

    public:

        virtual ~Scene() noexcept = default;

        /* 初期化処理 */
        virtual void Initialize() noexcept;

        /* ゲームを終了するか？ */
        [[nodiscard]]
        virtual bool IsExitGame() const noexcept;

        /* シーン遷移処理 */
        virtual void Transition() const noexcept = 0;

        /* 更新処理 */
        virtual void Update() noexcept = 0;

        /* 描画処理 */
        virtual void Render() const noexcept = 0;

        Scene(const Scene&) = delete;

        Scene& operator=(const Scene&) = delete;
    };
}
