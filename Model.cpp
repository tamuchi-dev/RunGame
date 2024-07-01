#include <DxLib.h>
#include "Vector.hpp"
#include "Model.hpp"

namespace Game
{
    void Model::Render(const Vector& position) const noexcept
    {
        const auto pos = VECTOR
        {
            static_cast<float32>(position.x),
            static_cast<float32>(position.y),
            static_cast<float32>(position.z)
        };

        MV1SetPosition(model, pos);
        MV1DrawModel(model);
    }

    void Model::Render(const Vector& position, const Vector& angle) const noexcept
    {
        const auto pos = VECTOR
        {
            static_cast<float32>(position.x),
            static_cast<float32>(position.y),
            static_cast<float32>(position.z)
        };
        const auto ang = VECTOR
        {
            static_cast<float32>(angle.x),
            static_cast<float32>(angle.y),
            static_cast<float32>(angle.z)
        };

        MV1SetPosition(model, pos);
        MV1SetRotationXYZ(model, ang);
        MV1DrawModel(model);
    }
}
