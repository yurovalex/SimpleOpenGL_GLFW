#pragma once
#include "backends/imgui_impl_glfw.h"


namespace SomeInterface {

class Interface
{
private:
    bool m_rotateflag;
    int  m_koef_RedColor;
public:
    Interface(bool rotateflag = false,int koef = 1):
                           m_rotateflag(rotateflag),
                           m_koef_RedColor(koef)
    {
    }

    void InitImGui(GLFWwindow* window);
    void UsingImGui(GLFWwindow* window);
    void DestroyImGui();
    bool GetRotateflag() const
    {
        return m_rotateflag;
    }
    int GetGradientRedColor() const
    {
        return m_koef_RedColor;
    }

};
}
