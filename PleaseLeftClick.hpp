#pragma once
#include "Framework.hpp"

namespace Game
{
    class PleaseLeftClick final
    {
        /* �摜 */
        Sprite sprite;

        /* �z�u���W */
        Vector position;

        /* �����x��ω�������� */
        int32 addAlphaValue;

        /* ���݂̓����x */
        int32 nowAlpha;

    public:

        [[nodiscard]]
        PleaseLeftClick() noexcept;
        
        /* ���������� */
        void Initialize() noexcept;

        /* �X�V���� */
        void Update() noexcept;

        /* �`�揈�� */
        void Render() const noexcept;
    };
}
