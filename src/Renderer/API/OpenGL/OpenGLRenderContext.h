#pragma once

#include "Renderer/RenderContext.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace OpenGL
{
    class OpenGLRenderContext : public RenderContext
    {
    public:
        OpenGLRenderContext(GLFWwindow* window);
        ~OpenGLRenderContext();

        virtual void Init() override;
        virtual void SwapBuffer() override;
    private:
        GLFWwindow* m_Window;
    };
}
