#include "Skydome.hpp"

namespace Game
{
    void Skydome::Initialize() noexcept
    {
        /* �������Ȃ� */
    }

    void Skydome::Update() noexcept
    {
        angle.y -= rotationSpeed * FrameRate::GetDeltaTime();
    }

    void Skydome::Render() const noexcept
    {
        model.Render(position, angle);
    }
}
