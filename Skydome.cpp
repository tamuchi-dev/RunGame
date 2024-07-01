#include "Skydome.hpp"

namespace Game
{
    void Skydome::Initialize() noexcept
    {
        /* ‰½‚à‚µ‚È‚¢ */
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
