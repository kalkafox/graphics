#include "sceneview.h"

namespace PhyG{
    bool DrawSceneView(){
        static bool p_open = true;

        // Construct on the stack
        static SquareWell sqw;

        if(p_open){
            sqw.step(2);

            ImGui::Begin("Scene View", &p_open, 0);
            ImGui::PlotLines("", (float*) sqw.expect_arr, 1000, 0, NULL, FLT_MAX, FLT_MAX, ImVec2(0, 120.0f));
            ImGui::End();
        }

        return p_open;
    }
}

//PlotLines(const char* label, const float* values, int values_count, int values_offset = 0, const char* overlay_text = NULL, float scale_min = FLT_MAX, float scale_max = FLT_MAX, ImVec2 graph_size = ImVec2(0, 0), int stride = sizeof(float));
