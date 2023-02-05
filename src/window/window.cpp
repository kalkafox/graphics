#include "window.h"

static void glfw_error_callback(int error, const char *description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

Window::Window() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        fprintf(stderr, "GLFW was unable to initalize...");
        return;
    }
#ifdef __APPLE__
    const char *glsl_version = "version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#elif
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
#endif

    window = glfwCreateWindow(WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_NAME, NULL, NULL);
    if (window == NULL){
        fprintf(stderr, "We couldn't create the window!");
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO(); (void)io;

#ifdef DARK_COLORS
    ImGui::StyleColorsDark();
#elif
    ImGui::StyleColorsClassic();
#endif

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    loop();
}
Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::loop() {
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();

        imgui_context->render(window);
        imgui_context->update();

        glfwSwapBuffers(window);
    }
}