#pragma once

#include <vector>
#include <utility>

enum class RendererAPI
{
    None = 0, OpenGL = 1
};

class Renderer
{   
public:
    static void Clear();

    inline static RendererAPI GetAPI() { return s_RendererAPI; }
private:
    static RendererAPI s_RendererAPI;
};


