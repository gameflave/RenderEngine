#pragma once

#include <string>
#include <unordered_map>
#include <GL/glew.h>
#include "stb_image/stb_image.h"


struct OpenGLTextureData{
    unsigned int RendererId;
    std::string FilePath;
    int Width, Height;
};

class OpenGLTexture
{
public:
    OpenGLTexture(const std::string& path);
    ~OpenGLTexture();

    void Bind(unsigned int slot=0) const;
    void Unbind() const;

    inline int GetWidth() const { return m_TexTureData->Width; }
    inline int GetHeight() const { return m_TexTureData->Height; }

private:
    OpenGLTextureData* m_TexTureData;

    //static std::unordered_map<std::string, TextureData> m_TextureCache;
};
