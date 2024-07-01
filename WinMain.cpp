#include <DxLib.h>
#include "Framework.hpp"
#include "ObjectDirector.hpp"
#include "SceneDirector.hpp"

using namespace Game;

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ INT)
{
    // =========================================
    // �V�X�e���ݒ�
    // =========================================

    /* ScreenFlip()�̐��������M����҂��Ȃ� */
    SetWaitVSyncFlag(false);
    /* DX���C�u��������������uLog.txt�v�𐶐����Ȃ� */
    SetOutApplicationLogValidFlag(false);
    /* �X�N���[���T�C�Y��ݒ� */
    Screen::SetSize(1920, 1080);
    /* �Q�[���̖��O��ݒ� */
    Screen::SetName("RunGame");
    /* �f�o�b�O���邩�����߂� */
    Debug::Enable();
    /* FPS��ݒ肷�� */
    FrameRate::targetFPS = 100;

    // =========================================
    // �Q�[���̋N������
    // =========================================

    if (Screen::Startup())
    {
        return EXIT_FAILURE;
    }
    FrameRate::Startup();
    ObjectDirector::GetInstance().Startup();
    SceneDirector::GetInstance().Startup();

    // =========================================
    // �Q�[�����[�v
    // =========================================

    while (not Screen::Update() && not SceneDirector::GetInstance().IsExitGame())
    {
        if (Input::IsKeyDown(KeyCode::Escape))
        {
            break;
        }

        FrameRate::Update();
        Input::Update();
        SceneDirector::GetInstance().Update();
        SceneDirector::GetInstance().Render();
        FrameRate::VSync();
    }

    // =========================================
    // �Q�[���I������
    // =========================================

    GraphLoader::DeleteAll();
    Screen::Cleanup();

    return EXIT_SUCCESS;
}
