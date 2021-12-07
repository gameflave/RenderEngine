#pragma once

#include <vector>
#include <utility>
#include <GL/glew.h>

#include "API/OpenGL/OpenGL.h"

enum class RendererAPI
{
    None = 0, OpenGL = 1
};

class Renderer
{   
public:
    static void Draw(const OpenGLVertexArray& va, const OpenGLIndexBuffer& ib, const OpenGLShader& shader);
    static void Clear();

    inline static RendererAPI GetAPI() { return s_RendererAPI; }
private:
    static RendererAPI s_RendererAPI;
};


