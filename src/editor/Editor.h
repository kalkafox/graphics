//
// Created by Brandon Boudreaux on 3/21/23.
//

#ifndef GRAPHICS_EDITOR_H
#define GRAPHICS_EDITOR_H

#include "imgui.h"
#include "GLFW/glfw3.h"
#include <filesystem>
#include <iostream>
#include <unordered_map>


namespace PhyG {
    class Editor{
    public:
        Editor();
        ~Editor();
        void Render();
        bool open = true;

    private:
        char text[1024];
        const ImGuiWindowFlags flags =  ImGuiWindowFlags_MenuBar;

        const ImGuiInputTextFlags text_edit_flags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_AllowTabInput;

        bool fe_open = false;
        const ImGuiWindowFlags fe_table_flags = ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_ScrollY | ImGuiTableFlags_Sortable | ImGuiTableFlags_Resizable;
        void FileExplorer();

        const char * default_path = "/Users/cee";
    };
}

#endif //GRAPHICS_EDITOR_H
