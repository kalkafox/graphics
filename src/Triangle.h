//
// Created by Brandon Boudreaux on 3/16/23.
//

#ifndef GRAPHICS_TRIANGLE_H
#define GRAPHICS_TRIANGLE_H

#include "RenderObject.h"

namespace PhyG {
    class Triangle : public PhyG::RenderObject {
    public:
        Triangle(std::string vertex_shader_location, std::string fragment_shader_location);
        ~Triangle();
    };
}

#endif //GRAPHICS_TRIANGLE_H
