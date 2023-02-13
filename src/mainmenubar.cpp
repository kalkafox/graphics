#include "mainmenubar.h"

namespace PhyG {
    bool DrawMenuBar() {
        static bool demo_p_open = false;

        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("Windows")) {
                if (ImGui::MenuItem("Show/Hide Demo")) {
                    demo_p_open = !demo_p_open;
                }
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
        if (demo_p_open) {
            ImGui::ShowDemoWindow(&demo_p_open);
        }

        return demo_p_open;
    }
}