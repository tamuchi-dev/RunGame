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

        Sprite confettiSp;
        int timer;

        struct Confetti
        {
            int interval;
            int index;
            Vector pos;
            bool isVisible;
        } confetti[100] = { 0 };

        bool first;

        float gameOverY;

        float gameOverGravity;

        float gameOverVY;

        float gameClearVS;

        float gameClearAddS;

        float gameClearWX;
        
        int gameClearEffFrame;

        bool isShowRanking;
        bool isPress;

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
