#include "TestBatchRendering.h"

namespace test {
    TestBatchRendering::TestBatchRendering()
        :m_DrawCallCount(0)
    {
    }
    TestBatchRendering::~TestBatchRendering()
    {

    }

    void TestBatchRendering::OnUpdate(float deltaTime)
    {

    }
    void TestBatchRendering::OnRender()
    {
        
    }
    void TestBatchRendering::OnImGuiRender()
    {
        ImGui::Begin("BatchRendering Test");
        ImGui::Text("DrawCall: %i", m_DrawCallCount);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }
}