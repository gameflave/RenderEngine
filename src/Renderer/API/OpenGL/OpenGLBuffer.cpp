#include "OpenGLBuffer.h"

//////////////////////////////////////////////////////////////////
//VertexBuffer
//////////////////////////////////////////////////////////////////

OpenGLVertexBuffer::OpenGLVertexBuffer(float* data, unsigned int size)
    :m_Layout({})
{
    glGenBuffers(1, &m_RendererId);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
    glDeleteBuffers(1, &m_RendererId);
}

void OpenGLVertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
}
void OpenGLVertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//////////////////////////////////////////////////////////////////
//IdexBuffer
//////////////////////////////////////////////////////////////////

OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* data, unsigned int count)
    :m_Count(count)
{
    glGenBuffers(1, &m_RendererId);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}
OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
    glDeleteBuffers(1, &m_RendererId);
}

void OpenGLIndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId);
}
void OpenGLIndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//////////////////////////////////////////////////////////////////
//BufferLayout
//////////////////////////////////////////////////////////////////
