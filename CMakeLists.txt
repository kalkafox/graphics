cmake_minimum_required(VERSION 3.23)
project(graphics)

set(CMAKE_CXX_STANDARD 17)

set(IMGUIDIR ${PROJECT_SOURCE_DIR}/imgui)

link_directories(/opt/homebrew/lib)

add_executable(phy_graphics src/main.cpp src/app.cpp imgui/imgui.cpp imgui/backends/imgui_impl_sdl.cpp imgui/backends/imgui_impl_opengl3.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/imgui_demo.cpp)

target_link_libraries(phy_graphics SDL2)
target_link_libraries(phy_graphics "-framework OpenGL")

target_include_directories(phy_graphics PRIVATE ${IMGUIDIR}/backends)
target_include_directories(phy_graphics PRIVATE ${IMGUIDIR})
target_include_directories(phy_graphics PRIVATE /opt/homebrew/include/SDL2)
