#pragma once
#include "Framework.hpp"

namespace Game
{
    class CircleFade final
    {
    public:

        enum class State
        {
            FadeInStart,
            FadeIn,
            FadeInEnd,
            FadeOutStart,
            FadeOut,
            FadeOutEnd,
        };

    private:

        Sprite sprite;

        int intervalFrame;

        int frameCounter;

        int nowID;

        State state;

    public:

        CircleFade();

        void Initialize();

        void Update();

        void Render();

        void FadeInStart()
        {
            if (state == State::FadeOutEnd) state = State::FadeInStart;
        }

        void FadeOutStart()
        {
            if (state == State::FadeInEnd) state = State::FadeOutStart;
        }

        bool IsFadeInEnd() { return state == State::FadeInEnd; }

        bool IsFadeOutEnd() { return state == State::FadeOutEnd; }
    };
}
