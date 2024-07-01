#pragma once
#include "BaseTypes.hpp"

namespace Game
{
    class FrameRate final
    {
        /* 前フレームの時間 */
        static int64 oldTime;

        /* 現フレームの時間 */
        static int64 nowTime;

        /* フレームチェック時間 */
        static int64 lastFrameCheckTime;

        /* フレームカウンタ */
        static int32 frameCount;

        /* 現在のFPS */
        static int32 nowFPS;

        /* デルタタイム */
        static float64 deltaTime;

        /* プログラムが起動してからの経過時間 */
        static int32 elapsedTime;

    public:

        /* 設定したFPS */
        static int32 targetFPS;

        friend class Debug;

        /* 起動準備 */
        static void Startup() noexcept;

        /* 更新処理 */
        static void Update() noexcept;

        /* 垂直同期をする */
        static void VSync() noexcept;

        /* デルタタイムを取得する */
        [[nodiscard]]
        static constexpr float64 GetDeltaTime() noexcept
        {
            return deltaTime;
        }

        /* プログラムが起動してからの経過時間を取得する */
        [[nodiscard]]
        static constexpr int32 GetElapsedTime() noexcept
        {
            return elapsedTime;
        }

    private:

        FrameRate() = default;

        FrameRate(const FrameRate&) = delete;

        FrameRate& operator=(const FrameRate&) = delete;
    };
}
