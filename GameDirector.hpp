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
        int32 nowScore = 0;

        /* 現在の制限時間 */
        int32 nowTimeLimit = 0;

        /* 経過デルタタイム */
        float64 elapsedDelta = 0;

        float64 time = 0;

        int32 wave = 0;

        /* 現在のイベント */
        Event nowEvent = Event::None;

        /* 現在のレベル */
        int32 nowLevel = 0;

        Sprite blackSprite;

        int alpha = 0;

        int dir = 0;

        int state = 0;

        int flg = 0;

        bool iscount = 0;

        int getSE = 0;
        bool setSEFlg = 0;

        float64 scrollOffsetX = 0;

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

        void Scroll() noexcept;

        /* 現在のスコアを取得する */
        [[nodiscard]]
        constexpr int32 GetNowScore() const noexcept
        {
            return nowScore;
        }

        [[nodiscard]]
        constexpr bool Iscount() const noexcept
        {
            return iscount;
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

        [[nodiscard]]
        constexpr float64 GetScrollOffsetX() const noexcept
        {
            return scrollOffsetX;
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
