#pragma once

#include <memory>

#include "Renderer/RendererAPI.h"
#include "Renderer/RenderCommand.h"

class Renderer
{   
public:
    static void BeginScene();
    static void EndScene();

    static void Submit(const std::shared_ptr<VertexArray>&);

    inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
private:
};


