#pragma once

#include "GL/glew.h"
  
class OpenGLIndexBuffer{
public:
    OpenGLIndexBuffer(const unsigned int* data, unsigned int count);
    ~OpenGLIndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const { return m_Count; };

private:
    unsigned int m_RendererId;
    unsigned int m_Count;
};