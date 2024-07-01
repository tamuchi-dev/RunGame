#include "Framework.hpp"
#include "GameDirector.hpp"
#include "ObjectDirector.hpp"
#include "SceneDirector.hpp"
#include "TestGenerator.hpp"

namespace Game
{
    void StageScene::Initialize() noexcept
    {
        GameDirector::GetInstance().Initialize();
        ObjectDirector::GetInstance().GetObstacleManager()->Initialize();
        ObjectDirector::GetInstance().GetCoinManager()->Initialize();
        ObjectDirector::GetInstance().GetPlayer()->Initialize();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<Countdown>()->Initialize();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<TimeLimit>()->Initialize();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<Score>()->Initialize();
        ObjectDirector::GetInstance().GetUIManager()->GetUI<LevelUp>()->Initialize();

        nowState = State::Coutdown;
    }

    void StageScene::Transition() const noexcept
    {
        if (GameDirector::GetInstance().GetNowEvent() == GameDirector::Event::GameClear)
        {
            SceneDirector::GetInstance().GetFade()->FadeInStart();

            if (SceneDirector::GetInstance().GetFade()->IsFadeInEnd())
            {
                SceneDirector::GetInstance().ChangeScene<ResultScene>();
            }
        }

        if (nowState == State::GameOver)
        {
            SceneDirector::GetInstance().GetFade()->FadeInStart();

            if (SceneDirector::GetInstance().GetFade()->IsFadeInEnd())
            {
                SceneDirector::GetInstance().ChangeScene<ResultScene>();
            }
        }
    }

    void StageScene::Update() noexcept
    {
        if (GameDirector::GetInstance().GetNowEvent() == GameDirector::Event::GameOver)
        {
            ObjectDirector::GetInstance().GetPlayer()->Dead();

            if (ObjectDirector::GetInstance().GetPlayer()->IsEndDead())
            {
                nowState = State::GameOver;
            }
        }
        else
        {
            switch (nowState)
            {
                case StageScene::State::Coutdown:
                    if (ObjectDirector::GetInstance().GetUIManager()->GetUI<Countdown>()->isEndCount())
                    {
                        nowState = State::NowGame;
                    }

                    ObjectDirector::GetInstance().GetSkydomeManager()->Update();
                    ObjectDirector::GetInstance().GetPlayer()->Update();
                    ObjectDirector::GetInstance().GetGround()->Update();
                    ObjectDirector::GetInstance().GetUIManager()->GetUI<Countdown>()->Update();
                    break;

                case StageScene::State::NowGame:
                    GameDirector::GetInstance().Update();
                    ObjectDirector::GetInstance().GetSkydomeManager()->Update();
                    ObjectDirector::GetInstance().GetPlayer()->Update();
                    ObjectDirector::GetInstance().GetGround()->Update();
                    ObjectDirector::GetInstance().GetObstacleManager()->Update();
                    ObjectDirector::GetInstance().GetCoinManager()->Update();
                    ObjectDirector::GetInstance().GetUIManager()->GetUI<LevelUp>()->Update();
                    break;

                default:
                    break;
            }
        }
    }

    void StageScene::Render() const noexcept
    {
        switch (nowState)
        {
        case StageScene::State::Coutdown:
            ObjectDirector::GetInstance().GetSkydomeManager()->Render();
            ObjectDirector::GetInstance().GetPlayer()->Render();
            ObjectDirector::GetInstance().GetGround()->Render();
            ObjectDirector::GetInstance().GetUIManager()->GetUI<Countdown>()->Render();
            break;

        case StageScene::State::NowGame:
            ObjectDirector::GetInstance().GetSkydomeManager()->Render();
            GameDirector::GetInstance().Render();
            ObjectDirector::GetInstance().GetObstacleManager()->Render();
            ObjectDirector::GetInstance().GetUIManager()->GetUI<CharaIcon>()->Render();
            ObjectDirector::GetInstance().GetCoinManager()->Render();
            ObjectDirector::GetInstance().GetPlayer()->Render();
            ObjectDirector::GetInstance().GetGround()->Render();
            ObjectDirector::GetInstance().GetUIManager()->GetUI<TimeLimit>()->Render();
            ObjectDirector::GetInstance().GetUIManager()->GetUI<Score>()->Render();
            ObjectDirector::GetInstance().GetUIManager()->GetUI<LevelUp>()->Render();
            break;

        case StageScene::State::GameOver:
            ObjectDirector::GetInstance().GetSkydomeManager()->Render();
            GameDirector::GetInstance().Render();
            ObjectDirector::GetInstance().GetObstacleManager()->Render();
            ObjectDirector::GetInstance().GetUIManager()->GetUI<CharaIcon>()->Render();
            ObjectDirector::GetInstance().GetCoinManager()->Render();
            ObjectDirector::GetInstance().GetPlayer()->Render();
            ObjectDirector::GetInstance().GetGround()->Render();
            ObjectDirector::GetInstance().GetUIManager()->GetUI<TimeLimit>()->Render();
            ObjectDirector::GetInstance().GetUIManager()->GetUI<Score>()->Render();
            ObjectDirector::GetInstance().GetUIManager()->GetUI<LevelUp>()->Render();
            break;

        default:
            break;
        }
    }
}
