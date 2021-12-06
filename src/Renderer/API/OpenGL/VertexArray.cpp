#include "VertexArray.h"

namespace OpenGL
{
    VertexArray::VertexArray()
    {
    glGenVertexArrays(1, &m_RendererId);
    }
    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererId);
    }

    void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
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

            offset += e.count * VertexBufferElement::GetSizeOfType(e.type);
        }

    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(m_RendererId);
    }
    void VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }
}