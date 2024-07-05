#pragma once
#include "Framework.hpp"
#include "Scene.hpp"

namespace Game
{
    class ResultScene final : public Scene
    {
        Sprite gameOver;

        Sprite gameClear;

        Sprite gameClearW;

        bool first;

        float gameOverY;

        float gameOverGravity;

        float gameOverVY;

        float gameClearVS;

        float gameClearAddS;

        float gameClearWX;
        
        int gameClearEffFrame;

    public:

        ResultScene();

        void Initialize() noexcept override;

        void Transition() const noexcept override;

        void Update() noexcept override;

        void Render() const noexcept override;

    private:

        void UpdateGameOver() noexcept;

        void UpdateGameClear() noexcept;
    };
}
