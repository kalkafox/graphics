//
// Created by Brandon Boudreaux on 3/21/23.
//

#include "Editor.h"
#include <iostream>

PhyG::Editor::Editor() {}

PhyG::Editor::~Editor() {}

void PhyG::Editor::FileExplorer() {
    ImGui::OpenPopup("File Explorer");
    if(ImGui::BeginPopupModal("File Explorer", &fe_open)){

        ImGui::Text("Choose a file to open:");
        ImGui::Separator();

        ImGui::Separator();
        ImGui::Button("Open");

        ImGui::EndPopup();
    }
}

void PhyG::Editor::Render() {
    if(!open){
        return;
    }

    ImGui::SetNextWindowSize(ImVec2(600, 900));
    ImGui::Begin("Lua Editor", &open, flags);

    if(ImGui::BeginMenuBar()){

        if(ImGui::BeginMenu("File")){

            ImGui::MenuItem("Open", NULL, &fe_open);

            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    ImGui::SetNextItemWidth(-FLT_MIN);
    ImGui::InputTextMultiline("##code", text, sizeof(text));

    if(fe_open){
        FileExplorer();
    }

    ImGui::End();
}