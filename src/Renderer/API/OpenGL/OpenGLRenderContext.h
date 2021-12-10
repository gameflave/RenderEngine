#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer/RenderContext.h"

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