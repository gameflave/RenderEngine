#include "Renderer.h"

RendererAPI Renderer::s_RendererAPI = RendererAPI::OpenGL;

void Renderer::Draw(const OpenGLVertexArray& va, const OpenGLIndexBuffer& ib, const OpenGLShader& shader)
{
    va.Bind();
    ib.Bind();
    shader.Bind();

    glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Clear()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}