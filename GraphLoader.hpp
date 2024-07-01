#pragma once
#include <string>
#include <unordered_map>
#include "BaseTypes.hpp"

namespace Game
{
    class GraphLoader final
    {
        /* �摜�n���h���R���e�i */
        static std::unordered_map<const char*, int32> sprite;

        /* ���f���n���h���R���e�i */
        static std::unordered_map<const char*, int32> model;

    public:

        ~GraphLoader() noexcept;

        /* �摜��ǂݍ��� */
        [[nodiscard]]
        static int32 LoadSprite(const char* filePath) noexcept;

        /* ���f����ǂݍ��� */
        [[nodiscard]]
        static int32 LoadModel(const char* filePath) noexcept;

        /* �ǂݍ��񂾃n���h����S�č폜���� */
        static void DeleteAll() noexcept;

    private:

        GraphLoader() = default;

        GraphLoader(const GraphLoader&) = delete;

        GraphLoader& operator=(const GraphLoader&) = delete;
    };
}
