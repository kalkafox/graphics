//
// Created by Brandon Boudreaux on 3/16/23.
//

#include "Settings.h"

void PhyG::Menu::Settings(bool *close, ImVec4 *clear_color) {
    ImGui::Begin("Settings", close);

    ImGui::ColorEdit4("Clear Color", reinterpret_cast<float *>(clear_color));

    ImGui::End();
}