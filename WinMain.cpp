#include <DxLib.h>
#include "Framework.hpp"
#include "ObjectDirector.hpp"
#include "SceneDirector.hpp"

using namespace Game;

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ INT)
{
    // =========================================
    // システム設定
    // =========================================

    /* ScreenFlip()の垂直同期信号を待たない */
    SetWaitVSyncFlag(false);
    /* DXライブラリが生成する「Log.txt」を生成しない */
    SetOutApplicationLogValidFlag(false);
    /* スクリーンサイズを設定 */
    Screen::SetSize(1920, 1080);
    /* ゲームの名前を設定 */
    Screen::SetName("RunGame");
    /* デバッグするかを決める */
    Debug::Enable();
    /* FPSを設定する */
    FrameRate::targetFPS = 100;

    // =========================================
    // ゲームの起動準備
    // =========================================

    if (Screen::Startup())
    {
        return EXIT_FAILURE;
    }
    FrameRate::Startup();
    ObjectDirector::GetInstance().Startup();
    SceneDirector::GetInstance().Startup();

    // =========================================
    // ゲームループ
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
    // ゲーム終了処理
    // =========================================

    GraphLoader::DeleteAll();
    Screen::Cleanup();

    return EXIT_SUCCESS;
}
