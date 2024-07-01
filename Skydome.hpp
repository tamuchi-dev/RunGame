#pragma once
#include "Framework.hpp"

namespace Game
{
    class Skydome
    {
    protected:

        /* ��]���x */
        float64 rotationSpeed;

        /* 3D���f�� */
        Model model;

        /* �z�u���W */
        Vector position;

        /* �`��p�x */
        Vector angle;

    public:

        [[nodiscard]]
        Skydome() noexcept
        : rotationSpeed{ 0.05 } {}

        virtual ~Skydome() noexcept = default;

        /* ���������� */
        virtual void Initialize() noexcept;

        /* �X�V���� */
        virtual void Update() noexcept;

        /* �`�揈�� */
        virtual void Render() const noexcept;
    };
}
