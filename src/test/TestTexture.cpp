#include "TestTexture.h"


namespace test {
    TestTexture::TestTexture()
        :m_Positions{ -50.0f, -50.0f, 0.0f, 0.0f, 50.0f, -50.0f, 1.0f, 0.0f, 50.0f,  50.0f, 1.0f, 1.0f, -50.0f,  50.0f, 0.0f, 1.0f},
        m_Indices{ 0, 1, 2, 2, 3, 0},
        m_IB(m_Indices, 6),
        m_Proj(glm::ortho(0.0f, 640.0f, 0.0f, 480.0f, -1.0f, 1.0f)),
        m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
        m_Model(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
        m_MVP(m_Proj * m_View * m_Model),
        m_Shader("ressources/shaders/basic.shader"),
        m_Texture("ressources/textures/cpppp.png"),
        m_TranslationA(220, 240, 0),
        m_TranslationB(420, 240, 0)
    {
        OpenGLVertexBuffer vb(m_Positions, 4 * 4 * sizeof(float));
        
        OpenGLVertexBufferLayout layout;
        layout.Push(GL_FLOAT, 2);
        layout.Push(GL_FLOAT, 2);    
        m_VA.AddBuffer(vb, layout);       

        m_Shader.Bind();
        m_Shader.SetUniformMat4f("u_MVP", m_MVP);

        m_Texture.Bind();
        m_Shader.SetUniform1i("u_texture", 0);

        m_VA.Unbind();
        m_Shader.Unbind();
        vb.Unbind();
        m_IB.Unbind();
    }
    TestTexture::~TestTexture()
    {

    }

    void TestTexture::OnUpdate(float deltaTime)
    {
        
    }
    void TestTexture::OnRender()
    {
        {
        m_Shader.Bind();
        
        m_Model = glm::translate(glm::mat4(1.0f), m_TranslationA);
        m_MVP = m_Proj * m_View * m_Model;

        m_Shader.SetUniformMat4f("u_MVP", m_MVP);
        }
        m_Renderer.Draw(m_VA, m_IB, m_Shader);
        {
        m_Shader.Bind();

        m_Model = glm::translate(glm::mat4(1.0f), m_TranslationB);
        m_MVP = m_Proj * m_View * m_Model;

        m_Shader.SetUniformMat4f("u_MVP", m_MVP);
        }
        m_Renderer.Draw(m_VA, m_IB, m_Shader);
    }
    void TestTexture::OnImGuiRender()
    {
        ImGui::Begin("Debug");
        ImGui::SliderFloat3("Translation A", &m_TranslationA.x, 0.0f, 700.0f);
        ImGui::SliderFloat3("Translation B", &m_TranslationB.x, 0.0f, 700.0f);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }
}