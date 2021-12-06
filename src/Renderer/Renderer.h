#pragma once

#include <vector>
#include <utility>
#include <GL/glew.h>

#include "API/OpenGL/OpenGL.h"

class Renderer
{   
public:
    Renderer();
    ~Renderer();

    void Draw(const OpenGLVertexArray& va, const OpenGLIndexBuffer& ib, const OpenGLShader& shader) const;
    void Clear() const;
};


