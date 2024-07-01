#include <DxLib.h>
#include "Debug.hpp"
#include "Vector.hpp"
#include "Sprite.hpp"

namespace Game
{
    void Sprite::Add(int32 handle) noexcept
    {
        handles.emplace_back(handle);
    }

    void Sprite::Render(const Vector& position, bool isFlipX, bool isFlipY) const noexcept
    {
        DrawRotaGraphF
        (
            static_cast<float32>(position.x),
            static_cast<float32>(position.y),
            scale,
            angle,
            handles[0],
            true,
            isFlipX,
            isFlipY
        );
    }

    void Sprite::Render(const Vector& position, int32 index, bool isFlipX, bool isFlipY) const noexcept
    {
        if (index < 0 || index >= handles.size())
        {
            Debug::ErrorMessageBox("指定したインデックスが範囲外を指しています。");
        }

        DrawRotaGraphF
        (
            static_cast<float32>(position.x),
            static_cast<float32>(position.y),
            scale,
            angle,
            handles[index],
            true,
            isFlipX,
            isFlipY
        );
    }
}
