#pragma once

#include "GL/glew.h"
#include "Renderer/Buffer.h"


class OpenGLVertexBuffer : public VertexBuffer{
public:
    OpenGLVertexBuffer(float* data, unsigned int size);
    ~OpenGLVertexBuffer();

    void Bind() const override;
    void Unbind() const override;

private:
    unsigned int m_RendererId;
};

class OpenGLIndexBuffer : public IndexBuffer{
public:
    OpenGLIndexBuffer(unsigned int* data, unsigned int count);
    ~OpenGLIndexBuffer();

    void Bind() const override;
    void Unbind() const override;

    inline unsigned int GetCount() const { return m_Count; };

private:
    unsigned int m_RendererId;
    unsigned int m_Count;
};