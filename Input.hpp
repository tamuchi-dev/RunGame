#pragma once
#include "BaseTypes.hpp"
#include "Vector.hpp"

namespace Game
{
    /* キーコード情報 */
    enum class KeyCode
    {
        Return    = 0x1C,   /* エンターキー */
        Space     = 0x39,   /* スペースキー */
        BackSpace = 0x0E,   /* バックスペースキー */
        Tab       = 0x0F,   /* タブキー */
        Escape    = 0x01,   /* エスケープキー */

        ShiftL = 0x2A,      /* 左シフトキー */
        ShiftR = 0x36,      /* 右シフトキー */
        CtrlL  = 0x1D,      /* 左コントロールキー */
        CtrlR  = 0x9D,      /* 右コントロールキー */

        ArrowL = 0xCB,      /* 左矢印キー */
        ArrowU = 0xC8,      /* 上矢印キー */
        ArrowR = 0xCD,      /* 右矢印キー */
        ArrowD = 0xD0,      /* 下矢印キー */

        _0 = 0x0B, _5 = 0x06,
        _1 = 0x02, _6 = 0x07,
        _2 = 0x03, _7 = 0x08,
        _3 = 0x04, _8 = 0x09,
        _4 = 0x05, _9 = 0x0A,

        A = 0x1E, J = 0x24, S = 0x1F,
        B = 0x30, K = 0x25, T = 0x14,
        C = 0x2E, L = 0x26, U = 0x16,
        D = 0x20, M = 0x32, V = 0x2F,
        E = 0x12, N = 0x31, W = 0x11,
        F = 0x21, O = 0x18, X = 0x2D,
        G = 0x22, P = 0x19, Y = 0x15,
        H = 0x23, Q = 0x10, Z = 0x2C,
        I = 0x17, R = 0x13,
    };

    /* マウスコード情報 */
    enum class MouseCode
    {
        ButtonL = 0x0001,   /* 左クリックボタン */
        ButtonM = 0x0004,   /* ミドルクリックボタン */
        ButtonR = 0x0002,   /* 右クリックボタン */
    };

    class Input final
    {
        /* キーの入力情報 */
        static int32 keyState[256];

        /* 前フレームのマウス入力情報 */
        static int32 oldMouseState;

        /* 現フレームのマウス入力情報 */
        static int32 nowMouseState;

        /* マウスカーソルの座標 */
        static Vector cursorPos;

    public:

        /* 更新処理 */
        static void Update() noexcept;

        /* キーを押した瞬間か？を判定する */
        [[nodiscard]]
        static constexpr bool IsKeyDown(KeyCode keyCode) noexcept
        {
            return keyState[static_cast<int32>(keyCode)] == 1;
        }

        /* キーを押しているか？を判定する */
        [[nodiscard]]
        static constexpr bool IsKeyHold(KeyCode keyCode) noexcept
        {
            return keyState[static_cast<int32>(keyCode)] >= 2;
        }

        /* キーを離した瞬間か？を判定する */
        [[nodiscard]]
        static constexpr bool IsKeyUp(KeyCode keyCode) noexcept
        {
            return keyState[static_cast<int32>(keyCode)] == -1;
        }

        /* マウスボタンを押した瞬間か？を判定する */
        [[nodiscard]]
        static constexpr bool IsMouseButtonDown(MouseCode mouseCode) noexcept
        {
            const auto code = static_cast<int32>(mouseCode);

            return (nowMouseState & code) && not (oldMouseState & code);
        }

        /* マウスボタンを押しているか？を判定する */
        [[nodiscard]]
        static constexpr bool IsMouseButtonHold(MouseCode mouseCode) noexcept
        {
            const auto code = static_cast<int32>(mouseCode);

            return (nowMouseState & code) && (oldMouseState & code);
        }

        /* マウスボタンを離した瞬間か？を判定する */
        [[nodiscard]]
        static constexpr bool IsMouseButtonUp(MouseCode mouseCode) noexcept
        {
            const auto code = static_cast<int32>(mouseCode);

            return not (nowMouseState & code) && (oldMouseState & code);
        }

        /* マウスカーソルの座標を取得する */
        [[nodiscard]]
        static constexpr Vector GetCursorPos() noexcept
        {
            return cursorPos;
        }

    private:

        Input() = default;

        Input(const Input&) = delete;

        Input& operator=(const Input&) = delete;
    };
}
