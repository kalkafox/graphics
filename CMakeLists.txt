cmake_minimum_required(VERSION 3.23)
project(graphics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wdeprecated-declarations")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wdeprecated-declarations")

set(SOURCES
        src/main.cpp
        src/window.cpp
        src/MainMenuBar.cpp
        src/Shader.cpp
        src/RenderObject.cpp
        src/Cube.cpp
        src/menus/Settings.cpp

        imgui/imgui.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_demo.cpp
        imgui/backends/imgui_impl_opengl3.cpp
        imgui/backends/imgui_impl_glfw.cpp src/Cube.cpp src/Cube.h)

add_executable(phy_graphics ${SOURCES})

# You should also build these yourself first :>
set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/imgui)
set(GLFW_DIR ${PROJECT_SOURCE_DIR}/glfw)
#set(IMPLOT_DIR ${PROJECT_SOURCE_DIR}/implot)
set(GLEW_DIR ${PROJECT_SOURCE_DIR}/glew)

target_link_directories(phy_graphics PRIVATE ${GLFW_DIR}/build/src)
target_link_directories(phy_graphics PRIVATE ${GLEW_DIR}/lib)

#target_include_directories(phy_graphics PRIVATE ${IMPLOT_DIR})
target_include_directories(phy_graphics PRIVATE ${IMGUI_DIR}/backends)
target_include_directories(phy_graphics PRIVATE ${IMGUI_DIR})
target_include_directories(phy_graphics PRIVATE ${GLFW_DIR}/include)
target_include_directories(phy_graphics PRIVATE ${GLEW_DIR}/include)
target_include_directories(phy_graphics PRIVATE ${PROJECT_SOURCE_DIR}/src/menus)

target_link_libraries(phy_graphics PRIVATE glfw3)
target_link_libraries(phy_graphics PRIVATE GLEW)

if (CMAKE_HOST_SYSTEM_NAME MATCHES "Linux")
    #Needs to be tested
    target_link_libraries(phy_graphics PRIVATE GL)
elseif (CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    target_link_libraries(phy_graphics PRIVATE "-framework OpenGL -framework Cocoa -framework IOkit")
elseif (CMAKE_HOST_SYSTEM_NAME MATCHES "Windows")
    #Needs to be tested
    target_link_libraries(phi_graphics PRIVATE opengl32)
else ()
    message(WARNING "Unsupported system: ${CMAKE_HOST_SYSTEM_NAME}")
endif ()
