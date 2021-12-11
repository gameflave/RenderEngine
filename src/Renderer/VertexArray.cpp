#include "VertexArray.h"

#include "Renderer/API/OpenGL/OpenGLVertexArray.h"

VertexArray* VertexArray::Create()
{
    switch (Renderer::GetAPI())
    {
    case RendererAPI::None:     return nullptr;
    case RendererAPI::OpenGL:   return new OpenGLVertexArray();
    }
}