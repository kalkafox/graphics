//
// Created by Brandon Boudreaux on 3/21/23.
//

#ifndef GRAPHICS_EDITOR_H
#define GRAPHICS_EDITOR_H

#include "imgui.h"
#include "tab.h"
#include "GLFW/glfw3.h"
#include <filesystem>
#include <iostream>
#include <unordered_map>
#include <vector>


namespace PhyG {
    class Editor{
    public:
        Editor();
        ~Editor();
        void Render();
        bool open = false;
    private:
        const ImGuiWindowFlags flags =  ImGuiWindowFlags_MenuBar;

        std::unordered_map<std::string, std::unique_ptr<Tab> > tabs;

        bool fe_open = false;
        const ImGuiWindowFlags fe_table_flags = ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_ScrollY | ImGuiTableFlags_Sortable | ImGuiTableFlags_Resizable;
        void FileExplorer();
        void RecurseDrawFiles(std::filesystem::path p);

        const char * default_path = "/Users/cee";
    };
}

#endif //GRAPHICS_EDITOR_H
