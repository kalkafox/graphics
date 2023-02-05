#pragma once
#define GL_SILENCE_DEPRECATION
#include "../config.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <cstdio>
#include <stdio.h>

#include <GLFW/glfw3.h>

#include <memory>

#include "../context/ImGuiContext.h"
class Window{
public:
	Window();
    ~Window();
	void loop();
private:
    GLFWwindow *window;
    bool shouldClose = false;
    std::unique_ptr<ImGuiContext> imgui_context = std::make_unique<ImGuiContext>();
};
