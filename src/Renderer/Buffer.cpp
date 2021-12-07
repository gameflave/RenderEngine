#include "Buffer.h"

VertexBuffer* VertexBuffer::Create(float* vertices, unsigned int size)
{
    switch (Renderer::GetAPI())
    {
    case RendererAPI::None:     return nullptr;
    case RendererAPI::OpenGL:   return new OpenGLVertexBuffer(vertices, size);
    }
}

IndexBuffer* IndexBuffer::Create(unsigned int* indices, unsigned int count)
{
    switch (Renderer::GetAPI())
    {
    case RendererAPI::None:     return nullptr;
    case RendererAPI::OpenGL:   return new OpenGLIndexBuffer(indices, count);
    }
}