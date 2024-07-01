#pragma once
#include <string>
#include <unordered_map>
#include "BaseTypes.hpp"

namespace Game
{
    class GraphLoader final
    {
        /* 画像ハンドルコンテナ */
        static std::unordered_map<const char*, int32> sprite;

        /* モデルハンドルコンテナ */
        static std::unordered_map<const char*, int32> model;

    public:

        ~GraphLoader() noexcept;

        /* 画像を読み込む */
        [[nodiscard]]
        static int32 LoadSprite(const char* filePath) noexcept;

        /* モデルを読み込む */
        [[nodiscard]]
        static int32 LoadModel(const char* filePath) noexcept;

        /* 読み込んだハンドルを全て削除する */
        static void DeleteAll() noexcept;

    private:

        GraphLoader() = default;

        GraphLoader(const GraphLoader&) = delete;

        GraphLoader& operator=(const GraphLoader&) = delete;
    };
}
