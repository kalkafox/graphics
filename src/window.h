#ifndef PHY_GRAPHICS_WINDOW_H
#define PHY_GRAPHICS_WINDOW_H

#include "config.h"
#include "Triangle.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

//#include "GL/glew.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <stdio.h>
#include "Settings.h"

class Window{
public:
	Window();
    ~Window();
	void run();
private:
    GLFWwindow *window;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    bool show_settings = false;
    PhyG::Triangle *c;
};
#endif