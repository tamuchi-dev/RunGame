#include "SunnyDome.hpp"

namespace Game
{
    SunnyDome::SunnyDome() noexcept
    {
        model.Set(GraphLoader::LoadModel("Asset/Model/Sunny/Dome_x503.pmx"));

        Initialize();
    }

    void SunnyDome::Initialize() noexcept
    {
        position = Vector{ 1000, 800, -50 };

        angle = Vector{ 0, -30, 0 };
    }
}
