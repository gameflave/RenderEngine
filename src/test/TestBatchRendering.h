#pragma onceS

#include "Test.h"
#include "imgui/imgui.h"

namespace test {
    class TestBatchRendering : public Test
    {
    public:
        TestBatchRendering();
        ~TestBatchRendering();

        void OnUpdate(float deltaTime);
        void OnRender();
        void OnImGuiRender();
    private:
        int m_DrawCallCount;
    };
}