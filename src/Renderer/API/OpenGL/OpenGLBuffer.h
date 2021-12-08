#pragma once

#include "GL/glew.h"
#include "Renderer/Buffer.h"

//////////////////////////////////////////////////////////////////
//VertexBuffer
//////////////////////////////////////////////////////////////////

class OpenGLVertexBuffer : public VertexBuffer{
public:
    OpenGLVertexBuffer(float* data, unsigned int size);
    ~OpenGLVertexBuffer();

    void Bind() const override;
    void Unbind() const override;

    inline void SetLayout(const BufferLayout& layout) override {m_Layout = layout;}
    inline const BufferLayout& GetLayout() const override {return m_Layout;}

private:
    unsigned int m_RendererId;
    BufferLayout m_Layout;
};

//////////////////////////////////////////////////////////////////
//IdexBuffer
//////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////
//BufferLayout
//////////////////////////////////////////////////////////////////
