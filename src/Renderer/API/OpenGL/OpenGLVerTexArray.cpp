#include "OpenGLVertexArray.h"

OpenGLVertexArray::OpenGLVertexArray()
{
glGenVertexArrays(1, &m_RendererId);
}
OpenGLVertexArray::~OpenGLVertexArray()
{
    glDeleteVertexArrays(1, &m_RendererId);
}

void OpenGLVertexArray::AddBuffer(const OpenGLVertexBuffer& vb, const BufferLayout& layout)
{
    Bind();
    vb.Bind();
    
    const auto& elements = layout.GetElements();
    for(unsigned int i=0; i<elements.size(); i++)
    {
        const auto& e = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, e.GetElementCount(), ShaderDataTypeToopenGLBaseType(e.Type), e.Normalized ? GL_TRUE : GL_FALSE, layout.GetStride(), (const void*)e.Offset);
    }

}

void OpenGLVertexArray::Bind() const
{
    glBindVertexArray(m_RendererId);
}
void OpenGLVertexArray::Unbind() const
{
    glBindVertexArray(0);
}