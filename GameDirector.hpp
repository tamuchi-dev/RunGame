#pragma once
#include "Framework.hpp"

namespace Game
{
    class GameDirector final
    {
    public:

        enum class Event
        {
            /* ゲームクリアイベント */
            GameClear,

            /* ゲームオーバーイベント */
            GameOver,

            /* イベントなし */
            None,
        };

    private:

        /* 現在のスコア */
        int32 nowScore;

        /* 現在の制限時間 */
        int32 nowTimeLimit;

        /* 経過デルタタイム */
        float64 elapsedDelta;

        float64 time;

        int32 wave;

        /* 現在のイベント */
        Event nowEvent;

        /* 現在のレベル */
        int32 nowLevel;

        Sprite blackSprite;

        int alpha;

        int dir;

        int state;

        int flg;

    public:

        /* 初期化処理 */
        void Initialize() noexcept;

        /* 更新処理 */
        void Update() noexcept;

        void Render();

        void Stage() noexcept;

        void Level1() noexcept;

        void Level2() noexcept;

        void Level3() noexcept;

        void Level4() noexcept;

        void Level5() noexcept;

        /* 現在のスコアを取得する */
        [[nodiscard]]
        constexpr int32 GetNowScore() const noexcept
        {
            return nowScore;
        }

        /* 現在の制限時間を取得する */
        [[nodiscard]]
        constexpr int32 GetNowTimeLimit() const noexcept
        {
            return nowTimeLimit;
        }

        /* 現在のイベントを取得する */
        [[nodiscard]]
        constexpr Event GetNowEvent() const noexcept
        {
            return nowEvent;
        }

        /* 実体を取得する */
        [[nodiscard]]
        static GameDirector& GetInstance() noexcept
        {
            static GameDirector instance;

            return instance;
        }

    private:

        GameDirector() = default;

        GameDirector(const GameDirector&) = delete;

        GameDirector& operator=(const GameDirector&) = delete;
    };
}
