//
// Created by Brandon Boudreaux on 3/21/23.
//

#include "Tab.h"

namespace PhyG{

    void Tab::LoadTextIn() {
        std::ifstream is(path.string());

        if (is) {
            // get length of file:
            is.seekg(0, is.end);
            int length = is.tellg();
            is.seekg(0, is.beg);

            buffer = new char[buffer_size];

            // read data as a block:
            is.read(buffer, length);

            is.close();

            std::cout << buffer << std::endl;
        }
    }

    Tab::Tab(std::filesystem::path p) {
        tab_title = p.filename().string();
        path = p;

        LoadTextIn();

    }

    Tab::~Tab() {
        delete[] buffer;
    }

    void Tab::Render() {
        if(!opened){
            return;
        }
        if(ImGui::BeginTabItem(tab_title.c_str(), &opened, 0)){
            ImVec2 text_size = ImGui::GetContentRegionAvail();
            ImGui::InputTextMultiline("##code", buffer, buffer_size, ImVec2(text_size.x, text_size.y-30));

            if(ImGui::GetIO().KeySuper && ImGui::IsKeyPressed(ImGuiKey_S)){
                std::cout << "Saving " << tab_title << std::endl;

                std::ofstream ofs(path.string());

                ofs.write(buffer, buffer_size);

                ofs.close();

                LoadTextIn();
            }
            ImGui::EndTabItem();
        }
    }

    std::string Tab::GetName() {
        return tab_title;
    }
}

// PhyG