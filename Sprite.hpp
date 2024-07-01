#pragma once
#include <vector>
#include "BaseTypes.hpp"

namespace Game
{
    class Sprite final
    {
        /* �摜�n���h���R���e�i */
        std::vector<int32> handles;

    public:

        /* �摜�̊g�嗦 */
        float64 scale;

        /* �摜�̊p�x */
        float64 angle;

        [[nodiscard]]
        constexpr Sprite() noexcept
        : scale{ 1 }
        , angle{ 0 } {}

        /* �摜��ǉ����� */
        void Add(int32 handle) noexcept;

        /* �摜��`�悷�� */
        void Render(const class Vector& position, bool isFlipX = false, bool isFlipY = false) const noexcept;

        /* �C���f�b�N�X���w�肵�ĉ摜��`�悷�� */
        void Render(const class Vector& position, int32 index, bool isFlipX = false, bool isFlipY = false) const noexcept;

        /* �摜�̑������擾���� */
        [[nodiscard]]
        constexpr int32 GetTotal() const noexcept
        {
            return static_cast<int32>(handles.size());
        }
    };
}
