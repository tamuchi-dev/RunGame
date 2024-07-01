#include <DxLib.h>
#include "Debug.hpp"
#include "GraphLoader.hpp"

namespace Game
{
    std::unordered_map<const char*, int32> GraphLoader::sprite;

    std::unordered_map<const char*, int32> GraphLoader::model;

    GraphLoader::~GraphLoader() noexcept
    {
        DeleteAll();
    }

    int32 GraphLoader::LoadSprite(const char* filePath) noexcept
    {
        const auto iter = sprite.find(filePath);

        if (iter != sprite.end())
        {
            return iter->second;
        }

        const auto handle = LoadGraph(filePath);

        if (handle == -1)
        {
            Debug::ErrorMessageBox("âÊëúÇÃì«Ç›çûÇ›Ç…é∏îsÇµÇ‹ÇµÇΩÅB");
        }

        sprite[filePath] = handle;

        return handle;
    }

    int32 GraphLoader::LoadModel(const char* filePath) noexcept
    {
        const auto iter = model.find(filePath);

        if (iter != model.end())
        {
            return iter->second;
        }

        const auto handle = MV1LoadModel(filePath);

        if (handle == -1)
        {
            Debug::ErrorMessageBox("ÉÇÉfÉãÇÃì«Ç›çûÇ›Ç…é∏îsÇµÇ‹ÇµÇΩÅB");
        }

        model[filePath] = handle;

        return handle;
    }

    void GraphLoader::DeleteAll() noexcept
    {
        for (auto& handle : sprite)
        {
            DeleteGraph(handle.second);
        }

        for (auto& handle : model)
        {
            MV1DeleteModel(handle.second);
        }
    }
}
