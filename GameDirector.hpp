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
        int32 nowScore;

        /* ���݂̐������� */
        int32 nowTimeLimit;

        /* �o�߃f���^�^�C�� */
        float64 elapsedDelta;

        float64 time;

        int32 wave;

        /* ���݂̃C�x���g */
        Event nowEvent;

        /* ���݂̃��x�� */
        int32 nowLevel;

        Sprite blackSprite;

        int alpha;

        int dir;

        int state;

        int flg;

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

        /* ���݂̃X�R�A���擾���� */
        [[nodiscard]]
        constexpr int32 GetNowScore() const noexcept
        {
            return nowScore;
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
