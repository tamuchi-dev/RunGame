#include "FrameRate.hpp"
#include "Sprite.hpp"
#include "Animation.hpp"

namespace Game
{
    void Animation::PlayLoop(const Sprite& sprite) noexcept
    {
        counter += FrameRate::GetDeltaTime();

        if (counter >= interval)
        {
            counter = 0;

            if (nowAnimID++; nowAnimID >= sprite.GetTotal())
            {
                nowAnimID = 0;
            }
        }
    }

    void Animation::PlayOnes(const Sprite& sprite) noexcept
    {
        counter += FrameRate::GetDeltaTime();

        if (counter >= interval)
        {
            counter = 0;

            if (nowAnimID++; nowAnimID >= sprite.GetTotal())
            {
                nowAnimID = sprite.GetTotal() - 1;
            }
        }
    }
}
