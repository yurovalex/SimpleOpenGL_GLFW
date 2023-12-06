#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "spdlog/spdlog.h"
#include <filesystem>
#include "GLFW/glfw3.h"
#include  "Interface.h"

namespace SomeInterface {
//Init imGui
void Interface::InitImGui(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplOpenGL3_Init();
    ImGuiIO &io = ImGui::GetIO();

    //how to get current directory
    std::string path = std::filesystem::current_path().generic_string();
    spdlog::info("current path: {0}", path);
    std::string s = "build/sources";
    std::string::size_type i = path.find(s);
    if (i != std::string::npos)
        path.erase(i, s.length());
    path.append("ttf/ExtraLight.ttf");
    //necessary path for the font
    spdlog::info("necessary path for the font: {0}", path);
    //add user font in form
    io.Fonts ->AddFontFromFileTTF(path.c_str(), 18, NULL,
                                 io.Fonts->GetGlyphRangesCyrillic());

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    // Setup Dear ImGui style
    ImGui::StyleColorsClassic();

}

//Using imGui
void Interface::UsingImGui(GLFWwindow* window)
{
    // feed inputs to dear imgui, start new frame

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();


    // render your GUI
    ImGui::Begin("Настройки");

    int width, height;
    glfwGetWindowSize(window, &width, &height);
    //spdlog::info("{0} x {1}", width, height );

    ImGui::SetWindowPos(ImVec2(width - 210, 10), ImGuiCond_::ImGuiCond_None);
    ImGui::SetWindowSize(ImVec2(200,200), ImGuiCond_::ImGuiCond_None);
    ImGui::Text("Вращение");
    // onButtonClick() event;
    if (ImGui::Button("Да/Нет")) {
        //rotateflag = true;
        m_rotateflag = m_rotateflag != false ? false : true;
    }

    if (ImGui::SliderInt("Цвет", &m_koef_RedColor, 1, 10))
    {

    }

    ImGui::End();

    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

}
//Free memory from ImGui
void Interface::DestroyImGui()
{
    //we must do some cleanup when the loop ends.
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

}
