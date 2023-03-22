//
// Created by Brandon Boudreaux on 3/21/23.
//

#ifndef GRAPHICS_EDITOR_H
#define GRAPHICS_EDITOR_H

#include "imgui.h"
#include "GLFW/glfw3.h"

namespace PhyG {
    class Editor{
    public:
        Editor();
        ~Editor();
        void Render();
        bool open = true;
    private:
        char text[1024];
        ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar;

        bool fe_open = false;
        void FileExplorer();
    };
}

#endif //GRAPHICS_EDITOR_H
