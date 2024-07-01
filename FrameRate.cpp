#include <DxLib.h>
#include "FrameRate.hpp"

namespace Game
{
    int32 FrameRate::targetFPS{ 60 };

    int64 FrameRate::nowTime{ 0 };

    int64 FrameRate::oldTime{ 0 };

    int64 FrameRate::lastFrameCheckTime{ 0 };

    int32 FrameRate::frameCount{ 0 };

    int32 FrameRate::nowFPS{ 0 };

    float64 FrameRate::deltaTime{ 0.00001 };

    int32 FrameRate::elapsedTime{ 0 };

    void FrameRate::Startup() noexcept
    {
        oldTime = GetNowHiPerformanceCount();
        lastFrameCheckTime = GetNowHiPerformanceCount();
    }

    void FrameRate::Update() noexcept
    {
        nowTime = GetNowHiPerformanceCount();

        deltaTime = (nowTime - oldTime) / 1000000.0;
        oldTime = nowTime;

        ++frameCount;
        if (nowTime - lastFrameCheckTime > 1000000)
        {
            ++elapsedTime;
            nowFPS = frameCount;
            frameCount = 0;
            lastFrameCheckTime = nowTime;
        }
    }

    void FrameRate::VSync() noexcept
    {
        WaitTimer(1000 / targetFPS);
    }
}
