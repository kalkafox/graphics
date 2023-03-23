//
// Created by Brandon Boudreaux on 3/21/23.
//

#include "Editor.h"

PhyG::Editor::Editor() {}

PhyG::Editor::~Editor() {}

void RecurseDrawFiles(std::filesystem::path p){
    for (const auto& entry : std::filesystem::directory_iterator(p))
    {
        if(entry.is_directory()){
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0);
            if(ImGui::TreeNodeEx(entry.path().filename().c_str(), ImGuiTreeNodeFlags_SpanFullWidth)){
                ImGui::Separator();
                RecurseDrawFiles(entry.path().string());
                ImGui::TreePop();
            }
        }else{
            static std::unordered_map<std::string, bool> selected;
            selected.insert( {entry.path().string(), false} );
            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0);

            ImGui::Selectable(entry.path().filename().c_str(), &selected.find(entry.path().string())->second);
        }
    }
}

void PhyG::Editor::FileExplorer() {
    ImGui::OpenPopup("File Explorer");
    if(ImGui::BeginPopupModal("File Explorer", &fe_open)){

        ImGui::Text("Choose a file to open:");
        ImGui::Separator();

        ImVec2 size = ImGui::GetContentRegionAvail();

        ImGui::BeginTable("File", 1, fe_table_flags, ImVec2(size.x, size.y-30));
        ImGui::TableSetupColumn("File");
        ImGui::TableHeadersRow();

        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        if(ImGui::TreeNodeEx(default_path, ImGuiTreeNodeFlags_SpanFullWidth)){
            RecurseDrawFiles(default_path);
            ImGui::TreePop();
        }

        ImGui::EndTable();

        ImGui::Separator();
        ImGui::Button("Open");

        ImGui::EndPopup();
    }
}

void PhyG::Editor::Render() {
    if(!open){
        return;
    }

    //ImGui::SetNextWindowSize(ImVec2(600, 900));
    ImGui::Begin("Lua Editor", &open, flags);

    if(ImGui::BeginMenuBar()){

        if(ImGui::BeginMenu("File")){

            ImGui::MenuItem("Open", NULL, &fe_open);

            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    // This will eventually be moved into tab view
    ImVec2 text_size = ImGui::GetContentRegionAvail();
    ImGui::InputTextMultiline("##code", text, sizeof(text), ImVec2(text_size.x, text_size.y-30), text_edit_flags);

    if(fe_open){
        FileExplorer();
    }

    ImGui::End();
}