#pragma once

#include "Test.h"
#include "GL/glew.h"
#include "imgui/imgui.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Renderer/API/OpenGL/OpenGL.h"
#include "Renderer/Renderer.h"

namespace test {
    class TestTexture : public Test
    {
    public:
        TestTexture();
        ~TestTexture();

        void OnUpdate(float deltaTime);
        void OnRender();
        void OnImGuiRender();
    private:
        float m_Positions[16];
        unsigned int m_Indices[6];
        OpenGLVertexArray m_VA; 
        OpenGLIndexBuffer m_IB;
        glm::mat4 m_Proj, m_View, m_Model, m_MVP;
        OpenGLShader m_Shader;
        OpenGLTexture m_Texture;
        glm::vec3 m_TranslationA, m_TranslationB;
        Renderer m_Renderer;
    };
}