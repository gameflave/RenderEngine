#include "Shader.h"

#include "Renderer/API/OpenGL/OpenGLShader.h"

Shader* Shader::Create(const std::string& filePath)
{
    switch (Renderer::GetAPI())
    {
    case RendererAPI::API::None:     return nullptr;
    case RendererAPI::API::OpenGL:   return new OpenGLShader(filePath);
    }
}