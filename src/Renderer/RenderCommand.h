#pragma once

#include <memory>

#include "Renderer/RendererAPI.h"
#include "Renderer/VertexArray.h"

class RenderCommand
{
public:
    inline static void Clear(const glm::vec4& color = {0.0f, 0.0f, 0.0f, 1.0f}) { s_RendererAPI->Clear(color); }

    inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) { s_RendererAPI->DrawIndexed(vertexArray); }
private:
    static RendererAPI* s_RendererAPI;
};