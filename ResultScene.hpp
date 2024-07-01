#pragma once
#include "Framework.hpp"
#include "Scene.hpp"

namespace Game
{
    class ResultScene final : public Scene
    {
        Sprite gameOver;

        Sprite gameClear;

        bool first;

    public:

        ResultScene();

        void Initialize() noexcept override;

        void Transition() const noexcept override;

        void Update() noexcept override;

        void Render() const noexcept override;
    };
}
