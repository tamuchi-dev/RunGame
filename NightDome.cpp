#include "NightDome.hpp"

namespace Game
{
    NightDome::NightDome() noexcept
    {
        model.Set(GraphLoader::LoadModel("Asset/Model/Night/Dome_Y901.pmx"));

        Initialize();
    }

    void NightDome::Initialize() noexcept
    {
        position = Vector{ 1000, 800, -50 };

        angle = Vector{ 0, -150, 0 };
    }
}
