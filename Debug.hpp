#pragma once
#include "BaseTypes.hpp"

namespace Game
{
    class Debug final
    {
        /* デバッグが有効か？ */
        static bool isEnable;

    public:

        /* デバッグを有効にする */
        static void Enable() noexcept;

        /* デバッグを無効にする */
        static void Disable() noexcept;

        /* 座標を指定してデバッグ表示をする */
        static void Log(int32 x, int32 y, const char* format, ...) noexcept;

        /* エラーメッセージボックスを表示 */
        static void ErrorMessageBox(const char* message) noexcept;

        /* コライダを表示する */
        static void Render(const class CircleColider& colider) noexcept;

        /* フレームレート情報を表示する */
        static void FrameRate() noexcept;

        /* 2Dの基準線を引く */
        static void BaseLine2D() noexcept;

    private:

        Debug() = default;

        Debug(const Debug&) = delete;

        Debug& operator=(const Debug&) = delete;
    };
}
