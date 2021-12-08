#include "Buffer.h"

//////////////////////////////////////////////////////////////////
//VertexBuffer
//////////////////////////////////////////////////////////////////


VertexBuffer* VertexBuffer::Create(float* vertices, unsigned int size)
{
    switch (Renderer::GetAPI())
    {
    case RendererAPI::None:     return nullptr;
    case RendererAPI::OpenGL:   return new OpenGLVertexBuffer(vertices, size);
    }
}

//////////////////////////////////////////////////////////////////
//IndexBuffer
//////////////////////////////////////////////////////////////////


IndexBuffer* IndexBuffer::Create(unsigned int* indices, unsigned int count)
{
    switch (Renderer::GetAPI())
    {
    case RendererAPI::None:     return nullptr;
    case RendererAPI::OpenGL:   return new OpenGLIndexBuffer(indices, count);
    }
}

//////////////////////////////////////////////////////////////////
//BufferLayout
//////////////////////////////////////////////////////////////////

BufferLayout::BufferLayout(const std::initializer_list<BufferElement> elements) 
    :m_Elements(elements)
{
    CalculateOffsetsAndStride();
}

void BufferLayout::CalculateOffsetsAndStride()
{
    unsigned int offset = 0;
    m_Stride = 0;
    for (auto& element : m_Elements)
    {
        element.Offset = offset;
        offset += element.Size;
        m_Stride += element.Size;
    }
}