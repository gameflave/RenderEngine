#include "OpenGLVertexArray.h"

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

OpenGLVertexArray::OpenGLVertexArray()
{
    glGenVertexArrays(1, &m_RendererId);
}
OpenGLVertexArray::~OpenGLVertexArray()
{
    glDeleteVertexArrays(1, &m_RendererId);
}

void OpenGLVertexArray::Bind() const
{
    glBindVertexArray(m_RendererId);
}
void OpenGLVertexArray::Unbind() const
{
    glBindVertexArray(0);
}

void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
{
    glBindVertexArray(m_RendererId);
    vertexBuffer->Bind();

    int i = 0;
    const auto& layout = vertexBuffer->GetLayout();
    for(const auto& element : layout.GetElements())
    {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(
            i,
            element.GetElementCount(),
            ShaderDataTypeToopenGLBaseType(element.Type),
            element.Normalized,
            layout.GetStride(),
            (const void*)element.Offset
        );
    }

    m_VertexBuffers.push_back(vertexBuffer);
}
void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
{
    glBindVertexArray(m_RendererId);
    indexBuffer->Bind();

    m_IndexBuffer = indexBuffer;
}