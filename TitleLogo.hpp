#pragma once
#include "Framework.hpp"

namespace Game
{
    class TitleLogo final
    {
        /* ‰æ‘œ */
        Sprite sprite;

        /* ”z’uÀ•W */
        Vector position;

    public:

        [[nodiscard]]
        TitleLogo() noexcept;

        /* ‰Šú‰»ˆ— */
        void Initialize() noexcept;

        /* •`‰æˆ— */
        void Render() const noexcept;
    };
}
