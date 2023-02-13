cmake_minimum_required(VERSION 3.23)
project(graphics)

set(CMAKE_CXX_STANDARD 17)

set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/imgui)
set(GLFW_DIR ${PROJECT_SOURCE_DIR}/glfw)

link_directories(${GLFW_DIR}/build/src)

set(SOURCES src/main.cpp src/window.cpp src/mainmenubar.cpp src/sceneview.cpp src/sceneview.h src/shader.cpp src/shader.h shapes/triangle.cpp shapes/triangle.h src/squarewell.cpp src/squarewell.h)
set(IMGUI_SRC imgui/imgui.cpp imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_opengl3.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/imgui_demo.cpp)

add_executable(phy_graphics ${SOURCES} ${IMGUI_SRC} )

target_link_libraries(phy_graphics glfw3)
target_link_libraries(phy_graphics "-framework OpenGL -framework Cocoa -framework IOkit")

target_include_directories(phy_graphics PRIVATE ${IMGUI_DIR}/backends)
target_include_directories(phy_graphics PRIVATE ${IMGUI_DIR})
target_include_directories(phy_graphics PRIVATE ${GLFW_DIR}/include)
