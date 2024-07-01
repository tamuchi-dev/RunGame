#include <DxLib.h>
#include "PleaseLeftClick.hpp"

namespace Game
{
    PleaseLeftClick::PleaseLeftClick() noexcept
    {
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/PleaseLeftClick.png"));

        Initialize();
    }

    void PleaseLeftClick::Initialize() noexcept
    {
        position = Vector{ 960, 850 };

        addAlphaValue = 3;

        nowAlpha = 0;
    }

    void PleaseLeftClick::Update() noexcept
    {
        nowAlpha += addAlphaValue;

        if (nowAlpha <= 0 || nowAlpha >= 255)
        {
            addAlphaValue *= -1;
        }
    }

    void PleaseLeftClick::Render() const noexcept
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, nowAlpha);
        sprite.Render(position);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
    }
}
