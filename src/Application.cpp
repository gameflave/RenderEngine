#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Renderer/Renderer.h"
#include "Window.h"

#include "imgui/imgui.h"

#include "test/Test.h"
#include "test/TestClearColor.h"
#include "test/TestTexture.h"
#include "test/TestBatchRendering.h"

int main(int argc, char *argv[])
{
    Window window((unsigned int)1280, (unsigned int)720, "OpenGL");

    test::Test* currentTest = nullptr;     
    test::TestMenu* testMenu = new test::TestMenu(currentTest);
    currentTest = testMenu;

    testMenu->RegisterTest<test::TestClearColor>("Clear Color");
    testMenu->RegisterTest<test::TestTexture>("2D Texture");
    testMenu->RegisterTest<test::TestBatchRendering>("Batch Rendering");
 
    //TODO event system
    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        ImGui_ImplGlfw_NewFrame();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        Renderer::Clear();
     
        if(currentTest)
        {
            currentTest->OnUpdate(0);
            currentTest->OnRender();
            ImGui::Begin("Test Menu");
            if(currentTest != testMenu && ImGui::Button("<-"))
            {
                delete currentTest;
                currentTest = testMenu;
            }
            currentTest->OnImGuiRender();
            ImGui::End();
        }

        window.OnUpdate();
    }

    delete currentTest;
    if(currentTest != testMenu) delete testMenu;

    return 0;
}