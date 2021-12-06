#pragma once

#include "Renderer/RenderContext.h"
#include "Renderer/API/OpenGL/OpenGLRenderContext.h"

#include <string>
#include <iostream>

#include <GLFW/glfw3.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"


class Window
{
public:
    Window(unsigned int width, unsigned int height, const std::string& title);
    ~Window();

    void SetEventCallback();
    void SetVSync(bool enable);

    void OnUpdate() const;

    inline GLFWwindow* GetWindow() const {return m_Window;}
    inline unsigned int GetWidth() const {return m_Width;}
    inline unsigned int GetHeight() const {return m_Height;}
private:
    GLFWwindow* m_Window;
    unsigned int m_Width, m_Height;
    RenderContext* m_Contex;
};