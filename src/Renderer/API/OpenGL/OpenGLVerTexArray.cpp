#include "OpenGLVertexArray.h"

OpenGLVertexArray::OpenGLVertexArray()
{
glGenVertexArrays(1, &m_RendererId);
}
OpenGLVertexArray::~OpenGLVertexArray()
{
    glDeleteVertexArrays(1, &m_RendererId);
}

void OpenGLVertexArray::AddBuffer(const OpenGLVertexBuffer& vb, const OpenGLVertexBufferLayout& layout)
{
    Bind();
    vb.Bind();
    
    const auto& elements = layout.GetElements();
    unsigned int offset = 0;
    for(unsigned int i=0; i<elements.size(); i++)
    {
        const auto& e = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, e.count, e.type, e.normalized, layout.GetStride(), (const void*)offset);

        offset += e.count * OpenGLVertexBufferElement::GetSizeOfType(e.type);
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