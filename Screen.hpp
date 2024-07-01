#pragma once
#include "BaseTypes.hpp"

namespace Game
{
    class Screen final
    {
    public:

        /* スクリーンの横幅 */
        static int32 sizeX;
        
        /* スクリーンの縦幅 */
        static int32 sizeY;

        /* 起動準備 */
        [[nodiscard]]
        static bool Startup() noexcept;

        /* 更新処理 */
        [[nodiscard]]
        static bool Update() noexcept;

        /* 終了処理 */
        static void Cleanup() noexcept;

        /* スクリーンの大きさを設定する */
        static void SetSize(int32 x, int32 y) noexcept;

        /* スクリーンバーに表示される名前を設定する */
        static void SetName(const char* name) noexcept;

    private:

        Screen() = default;

        Screen(const Screen&) = delete;

        Screen& operator=(const Screen&) = delete;
    };
}
