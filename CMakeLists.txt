cmake_minimum_required(VERSION 3.23)
project(graphics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wdeprecated-declarations")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wdeprecated-declarations")

# If you have these installed, you can instead just link against them.
set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/imgui)
set(GLFW_DIR ${PROJECT_SOURCE_DIR}/glfw)
set(IMPLOT_DIR ${PROJECT_SOURCE_DIR}/implot)

# This can be overriden to prefer local install but I prefer just to build against a specific version.
link_directories(${GLFW_DIR}/build/src)

set(SOURCES
        src/main.cpp
        src/window.cpp
        src/mainmenubar.cpp
        src/shader.cpp
        shapes/triangle.cpp

        implot/implot.cpp
        implot/implot_items.cpp
        implot/implot_demo.cpp

        imgui/imgui.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_demo.cpp
        imgui/backends/imgui_impl_opengl3.cpp
        imgui/backends/imgui_impl_glfw.cpp src/RenderObject.cpp src/RenderObject.h)

add_executable(phy_graphics ${SOURCES})

#macOS only right now (maybe always?)
target_link_libraries(phy_graphics glfw3)
target_link_libraries(phy_graphics "-framework OpenGL -framework Cocoa -framework IOkit")

target_include_directories(phy_graphics PRIVATE ${IMPLOT_DIR})
target_include_directories(phy_graphics PRIVATE ${IMGUI_DIR}/backends)
target_include_directories(phy_graphics PRIVATE ${IMGUI_DIR})
target_include_directories(phy_graphics PRIVATE ${GLFW_DIR}/include)
