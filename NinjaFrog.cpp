#include <DxLib.h>
#include "NinjaFrog.hpp"

namespace Game
{
    NinjaFrog::NinjaFrog() noexcept
    : jumpForce{ 1100 }
    , fallSpeed{ 4000 }
    , groundY{ 840 }
    , jumpCountMax{ 2 }
    {
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/01.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/02.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/03.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/04.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/05.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/06.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/07.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/08.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/09.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/10.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/11.png"));
        sprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/12.png"));
        jumpSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Jump.png"));
        fallSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Fall.png"));
        deadSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Dead/01.png"));
        deadSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Dead/02.png"));
        deadSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Dead/03.png"));
        deadSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Dead/04.png"));
        deadSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Dead/05.png"));
        deadSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Dead/06.png"));
        deadSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Dead/07.png"));
        idleSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Idle/01.png"));
        idleSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Idle/02.png"));
        idleSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Idle/03.png"));
        idleSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Idle/04.png"));
        idleSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Idle/05.png"));
        idleSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Idle/06.png"));
        idleSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Idle/07.png"));
        idleSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Idle/08.png"));
        idleSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Idle/09.png"));
        idleSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Idle/10.png"));
        idleSprite.Add(GraphLoader::LoadSprite("Asset/Sprite/NinjaFrog/Idle/11.png"));

        dieSE = LoadSoundMem("Asset/Sound/prick.mp3");
        jumpSE = LoadSoundMem("Asset/Sound/jump3.mp3");

        Initialize();
    }

    void NinjaFrog::Initialize() noexcept
    {
        sprite.scale = 3;

        sprite.angle = 0;

        jumpSprite.scale = 3;
        fallSprite.scale = 3;
        deadSprite.scale = 3;
        idleSprite.scale = 3;

        animation = Animation{ 0.05 };

        deadAnim = Animation{ 0.03 };

        idleAnim = Animation{ 0.08 };
        position = Vector{ 350, groundY };

        colider = CircleColider{ position, 25 };

        vectorY = 0;

        jumpCount = 0;

        isDead = false;
        dieSEFlg = true;
        jumpSEFlg = true;

        deadInterval = 0.8;
    }

    void NinjaFrog::Update() noexcept
    {
        /* ジャンプの開始トリガー */
        if (jumpCount < jumpCountMax && Input::IsMouseButtonDown(MouseCode::ButtonL))
        {
            ++jumpCount;
            vectorY = jumpForce;
            PlaySoundMem(jumpSE, DX_PLAYTYPE_BACK);
        }

        if (jumpCount > 0)
        {
            /* ジャンプと落下処理 */
            position.y -= vectorY * FrameRate::GetDeltaTime();
            vectorY -= fallSpeed * FrameRate::GetDeltaTime();

            /* 地面についたらジャンプ終了 */
            if (position.y > groundY)
            {
                position.y = groundY;
                jumpCount = 0;
            }
        }

        /* コライダの座標をオブジェクトに合わせる */
        colider.Set(position);

        /* アニメーション */
        animation.PlayLoop(sprite);
    }

    void NinjaFrog::OverUpdate()
    {
        position.x = (float64)Screen::sizeX / 2;
        idleAnim.PlayLoop(idleSprite);
    }

    void NinjaFrog::ClearUpdate()
    {
        position.x = (float64)Screen::sizeX / 2;
        if (jumpCount < jumpCountMax)
        {
            jumpCount = jumpCountMax;
            vectorY = jumpForce;
        }

        if (jumpCount > 0)
        {
            /* ジャンプと落下処理 */
            position.y -= vectorY * FrameRate::GetDeltaTime();
            vectorY -= fallSpeed * FrameRate::GetDeltaTime();

            /* 地面についたらジャンプ終了 */
            if (position.y > groundY)
            {
                position.y = groundY;
                jumpCount = 0;
            }
        }
        animation.PlayLoop(sprite);
    }

    void NinjaFrog::Dead() noexcept
    {
        isDead = true;

        if (dieSEFlg)
        {
            dieSEFlg = false;
            PlaySoundMem(dieSE, DX_PLAYTYPE_BACK);
        }

        deadAnim.PlayOnes(deadSprite);

        if (deadAnim.GetNowAnimID() == deadSprite.GetTotal() - 1)
        {
            if (deadInterval -= FrameRate::GetDeltaTime(); deadInterval < 0)
            {
                deadInterval = 0;
            }
        }
    }

    void NinjaFrog::Render() const noexcept
    {
        if (isDead)
        {
            if (deadAnim.GetNowAnimID() != deadSprite.GetTotal() - 1)
            {
                deadSprite.Render(position, deadAnim.GetNowAnimID());
            }
        }
        else if (position.y == groundY)
        {
            sprite.Render(position, animation.GetNowAnimID());
        }
        else
        {
            if (vectorY > 0)
            {
                jumpSprite.Render(position);
            }
            else
            {
                fallSprite.Render(position);
            }
        }
    }

    void NinjaFrog::OverRender()
    {
        idleSprite.Render(position, idleAnim.GetNowAnimID());
    }
}
