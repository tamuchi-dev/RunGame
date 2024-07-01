#include "CloudDome.hpp"

namespace Game
{
    CloudDome::CloudDome() noexcept
    {
        model.Set(GraphLoader::LoadModel("Asset/Model/Cloud/Dome_EE401.pmx"));

        Initialize();
    }

    void CloudDome::Initialize() noexcept
    {
        position = Vector{ 1000, 800, -50 };

        angle = Vector{ 0, -150, 0 };
    }
}
