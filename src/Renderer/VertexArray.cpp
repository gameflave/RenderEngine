#include "VertexArray.h"

#include "Renderer/API/OpenGL/OpenGLVertexArray.h"

VertexArray* VertexArray::Create()
{
    switch (Renderer::GetAPI())
    {
    case RendererAPI::API::None:     return nullptr;
    case RendererAPI::API::OpenGL:   return new OpenGLVertexArray();
    }
}