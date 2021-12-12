#pragma once

#include <GL/glew.h>

#include "Renderer/RendererAPI.h"

class OpenGLRendererAPI : public RendererAPI
{
public:
    virtual void Clear(const glm::vec4& color = {0.0f, 0.0f, 0.0f, 1.0f}) override;

    virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
};