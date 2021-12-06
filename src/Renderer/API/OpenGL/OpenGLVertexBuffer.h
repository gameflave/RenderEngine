#pragma once

#include "GL/glew.h"

class OpenGLVertexBuffer{
public:
    OpenGLVertexBuffer(const void* data, unsigned int size);
    ~OpenGLVertexBuffer();

    void Bind() const;
    void Unbind() const;

private:
    unsigned int m_RendererId;
};