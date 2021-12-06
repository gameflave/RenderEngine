#pragma once

#include "OpenGLBuffer.h"
#include "OpenGLVertexBufferLayout.h"

class OpenGLVertexArray
{
public:
    OpenGLVertexArray();
    ~OpenGLVertexArray();

    void AddBuffer(const OpenGLVertexBuffer& vb, const OpenGLVertexBufferLayout& layout);

    void Bind() const;
    void Unbind() const;
private:
    unsigned int m_RendererId;
};