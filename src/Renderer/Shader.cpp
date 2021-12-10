#include "Shader.h"

#include "Renderer/API/OpenGL/OpenGLShader.h"

Shader* Shader::Create(const std::string& filePath)
{
    switch (Renderer::GetAPI())
    {
    case RendererAPI::None:     return nullptr;
    case RendererAPI::OpenGL:   return new OpenGLShader(filePath);
    }
}