#include "MainMenuBar.h"

namespace PhyG {
    bool DrawMenuBar() {
        static bool p_open = false;
#ifdef DEBUG
        static bool demo_p_open = false;
#endif

        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("Windows")) {
#ifdef DEBUG
                if (ImGui::MenuItem("Dear ImGui Demo")) {
                    demo_p_open = !demo_p_open;
                }
#endif
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
#ifdef DEBUG
        if (demo_p_open) {
            ImGui::ShowDemoWindow(&demo_p_open);
        }
#endif

        return p_open;
    }
}