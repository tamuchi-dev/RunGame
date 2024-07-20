#pragma once
#include "Framework.hpp"

namespace Game
{
    class GameDirector final
    {
    public:

        enum class Event
        {
            /* �Q�[���N���A�C�x���g */
            GameClear,

            /* �Q�[���I�[�o�[�C�x���g */
            GameOver,

            /* �C�x���g�Ȃ� */
            None,
        };

    private:

        /* ���݂̃X�R�A */
        int32 nowScore = 0;

        /* ���݂̐������� */
        int32 nowTimeLimit = 0;

        /* �o�߃f���^�^�C�� */
        float64 elapsedDelta = 0;

        float64 time = 0;

        int32 wave = 0;

        /* ���݂̃C�x���g */
        Event nowEvent = Event::None;

        /* ���݂̃��x�� */
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

        /* ���������� */
        void Initialize() noexcept;

        /* �X�V���� */
        void Update() noexcept;

        void Render();

        void Stage() noexcept;

        void Level1() noexcept;

        void Level2() noexcept;

        void Level3() noexcept;

        void Level4() noexcept;

        void Level5() noexcept;

        void Scroll() noexcept;

        /* ���݂̃X�R�A���擾���� */
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

        /* ���݂̐������Ԃ��擾���� */
        [[nodiscard]]
        constexpr int32 GetNowTimeLimit() const noexcept
        {
            return nowTimeLimit;
        }

        /* ���݂̃C�x���g���擾���� */
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

        /* ���̂��擾���� */
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
