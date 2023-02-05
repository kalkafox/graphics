#ifndef APP
#define APP

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include <stdio.h>

#include <SDL.h>

#include <SDL_opengl.h>

#include <iostream>

class App{
public:
	App();
	~App();
	void run();
	void update();
	void render();
private:
	bool shouldClose = false;
	SDL_WindowFlags window_flags;
	SDL_Window* window;
	SDL_GLContext gl_context;

	ImGuiIO io;

	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};
#endif
