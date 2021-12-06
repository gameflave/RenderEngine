#pragma onceS

#include "Test.h"
#include "GL/glew.h"
#include "imgui/imgui.h"

namespace test {
    class TestClearColor : public Test
    {
    public:
        TestClearColor();
        ~TestClearColor();

        void OnUpdate(float deltaTime);
        void OnRender();
        void OnImGuiRender();
    private:
        float m_ClearColor[4];
    };
}