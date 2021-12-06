#include "OpenGLTexture.h"

OpenGLTexture::OpenGLTexture(const std::string& path)
    :m_TexTureData(nullptr)
{
    /* if(Texture::m_TextureCache.find(path) != Texture::m_TextureCache.end())
    {
        m_TexTureData = &Texture::m_TextureCache[path];
        return;
    } */

    OpenGLTextureData td;

    //OpenGL attend des Texture avec pour origine Bas Gauche
    //Les png Haut Gauche donc on flip en vertical
    stbi_set_flip_vertically_on_load(1); 
    
    int bpp = 0;
    void* localBuffer = stbi_load(path.c_str(), &td.Width, &td.Height, &bpp, 4);

    glGenTextures(1, &td.RendererId);
    glBindTexture(GL_TEXTURE_2D, td.RendererId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, td.Width, td.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);

    if (localBuffer)
        stbi_image_free(localBuffer);

    //m_TextureCache[path] = td;
}
OpenGLTexture::~OpenGLTexture()
{
    glDeleteTextures(1, &m_TexTureData->RendererId);
}

void OpenGLTexture::Bind(unsigned int slot) const
{
    glActiveTexture(GL_TEXTURE_2D + slot);
    glBindTexture(GL_TEXTURE_2D, m_TexTureData->RendererId);
}
void OpenGLTexture::Unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}