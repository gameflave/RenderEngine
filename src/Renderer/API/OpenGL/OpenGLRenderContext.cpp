#pragma once

#include "Renderer/API/OpenGL/OpenGLRenderContext.h"

#include <iostream>

namespace OpenGL
{
    OpenGLRenderContext::OpenGLRenderContext(GLFWwindow* window)
        :m_Window(window)
    {
    }

    OpenGLRenderContext::~OpenGLRenderContext()
    {
    }

    void OpenGLRenderContext::Init()
    {
        glfwMakeContextCurrent(m_Window);
        GLenum err = glewInit();
        if (GLEW_OK != err)
            fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void OpenGLRenderContext::SwapBuffer()
    {
        glfwSwapBuffers(m_Window);
    }
}