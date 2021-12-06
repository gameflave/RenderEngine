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

    void Draw(const OpenGL::VertexArray& va, const OpenGL::IndexBuffer& ib, const OpenGL::Shader& shader) const;
    void Clear() const;
};


