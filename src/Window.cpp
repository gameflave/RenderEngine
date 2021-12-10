#include "Window.h"

Window::Window(unsigned int width, unsigned int height, const std::string& title)
    :m_Width(width), m_Height(height)
{
    if (!glfwInit())
        fprintf(stderr, "Error: glfwInit()\n");

    m_Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!m_Window)
    {
        glfwTerminate();
        fprintf(stderr, "Error: glfwCreateWindow, w:%i h:%i t:%s\n", width, height, title);
    }
    
    m_Contex = new OpenGLRenderContext(m_Window);
    m_Contex->Init();

    SetVSync(true);

    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
}

void Window::SetVSync(bool enable)
{
    glfwSwapInterval(enable);
}

Window::~Window()
{
    delete m_Contex;

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
    glfwTerminate();
}

void Window::OnUpdate() const
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    m_Contex->SwapBuffer();
    glfwPollEvents();
}