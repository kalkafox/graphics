cmake_minimum_required(VERSION 3.23)
project(graphics)

set(CMAKE_CXX_STANDARD 17)

set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/imgui)
set(GLFW_DIR ${PROJECT_SOURCE_DIR}/glfw)

link_directories(${GLFW_DIR}/build/src)

set(SOURCES src/main.cpp src/app.cpp src/window/window.cpp src/context/context.h src/context/ImGuiContext.cpp src/context/ImGuiContext.h)

add_executable(phy_graphics ${SOURCES} imgui/imgui.cpp imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_opengl3.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/imgui_demo.cpp)

target_link_libraries(phy_graphics glfw3)
target_link_libraries(phy_graphics "-framework OpenGL -framework Cocoa -framework IOkit")

target_include_directories(phy_graphics PRIVATE ${IMGUI_DIR}/backends)
target_include_directories(phy_graphics PRIVATE ${IMGUI_DIR})
target_include_directories(phy_graphics PRIVATE ${GLFW_DIR}/include)
