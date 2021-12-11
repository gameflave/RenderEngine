#pragma once

#include <vector>
#include <memory>

#include <GL/glew.h>

#include "OpenGLBuffer.h"
#include "Renderer/VertexArray.h"

class OpenGLVertexArray : public VertexArray
{
public:
    OpenGLVertexArray();
    ~OpenGLVertexArray() {}

    virtual void Bind() const override;
    virtual void Unbind() const override;
    
    virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
    virtual void SetIndexBuffer(const std::shared_ptr<VertexBuffer>& indexBuffer) override;
private:
    std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
    std::shared_ptr<IndexBuffer> m_IndexBuffer;
    unsigned int m_RendererId;
};