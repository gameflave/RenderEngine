#include "OpenGLRendererAPI.h"

void Clear(const glm::vec4& color = {0.0f, 0.0f, 0.0f, 1.0f})
{
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
{
    vertexArray->Bind();
    glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
}