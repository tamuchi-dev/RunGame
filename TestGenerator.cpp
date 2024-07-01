#include "ObjectDirector.hpp"
#include "TestGenerator.hpp"

namespace Game
{
    void TestGenerator::Execute() noexcept
	{
        if (Input::IsKeyDown(KeyCode::_1))
        {
            ObjectDirector::GetInstance().GetObstacleManager()->Generate<GroundSpike>();
        }
        else if (Input::IsKeyDown(KeyCode::_2))
        {
            ObjectDirector::GetInstance().GetObstacleManager()->Generate<RotarySaw>();
        }
        else if (Input::IsKeyDown(KeyCode::_3))
        {
            ObjectDirector::GetInstance().GetObstacleManager()->Generate<SpikeBall>();
        }
        else if (Input::IsKeyDown(KeyCode::_4))
        {
            ObjectDirector::GetInstance().GetCoinManager()->Generate<RedCoin>(850);
        }
        else if (Input::IsKeyDown(KeyCode::_5))
        {
            ObjectDirector::GetInstance().GetCoinManager()->Generate<GoldCoin>(850);
        }
        else if (Input::IsKeyDown(KeyCode::_6))
        {
            ObjectDirector::GetInstance().GetCoinManager()->Generate<SilverCoin>(850);
        }
	}
}