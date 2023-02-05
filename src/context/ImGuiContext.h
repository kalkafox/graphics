#pragma once
#include "context.h"
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include <GLFW/glfw3.h>

#include "../config.h"

class ImGuiContext : Context<ImGuiContext> {
public:
    void render(GLFWwindow *window);
    void update();
private:
#ifdef DEBUG
    bool showDemo = true;
#else
    bool showDemo = false;
#endif
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};