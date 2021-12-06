#pragma once

#include <string>
#include <unordered_map>
#include <GL/glew.h>
#include "stb_image/stb_image.h"

namespace OpenGL
{
    struct TextureData{
        unsigned int RendererId;
        std::string FilePath;
        int Width, Height;
    };

    class Texture
    {
    public:
        Texture(const std::string& path);
        ~Texture();

        void Bind(unsigned int slot=0) const;
        void Unbind() const;

        inline int GetWidth() const { return m_TexTureData->Width; }
        inline int GetHeight() const { return m_TexTureData->Height; }

    private:
        TextureData* m_TexTureData;

        //static std::unordered_map<std::string, TextureData> m_TextureCache;
    };
}
