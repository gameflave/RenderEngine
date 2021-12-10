#pragma once

#include <GL/glew.h>

#include "OpenGLBuffer.h"

class OpenGLVertexArray
{
public:
    OpenGLVertexArray();
    ~OpenGLVertexArray();

    void AddBuffer(const OpenGLVertexBuffer& vb, const BufferLayout& layout);

    void Bind() const;
    void Unbind() const;
private:
    unsigned int m_RendererId;
};

static GLenum ShaderDataTypeToopenGLBaseType(ShaderDataType type)
{
    switch (type)
    {
    case ShaderDataType::Float:     return GL_FLOAT;
    case ShaderDataType::Float2:    return GL_FLOAT;
    case ShaderDataType::Float3:    return GL_FLOAT;
    case ShaderDataType::Float4:    return GL_FLOAT;
    case ShaderDataType::Mat3:      return GL_FLOAT;
    case ShaderDataType::Mat4:      return GL_FLOAT;
    case ShaderDataType::Int:       return GL_INT;
    case ShaderDataType::Int2:      return GL_INT;
    case ShaderDataType::Int3:      return GL_INT;
    case ShaderDataType::Int4:      return GL_INT;
    case ShaderDataType::Bool:      return GL_BOOL;
    default: fprintf(stderr, "Error: Unknow ShaderDataType"); return 0;
    }
}