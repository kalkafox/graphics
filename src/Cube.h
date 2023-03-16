//
// Created by Brandon Boudreaux on 3/16/23.
//

#ifndef PHY_GRAPHICS_CUBE_H
#define PHY_GRAPHICS_CUBE_H

#include "RenderObject.h"
#include "primatives.h"
#include "GL/glew.h"

#define verts PhyG::Primatives::Cube::vertices
#define indis PhyG::Primatives::Cube::indices

namespace PhyG{
    class Cube : public PhyG::RenderObject{
    public:
        Cube(std::string vertex_shader_location, std::string fragment_shader_location);
        ~Cube();
    };
}


#endif //PHY_GRAPHICS_CUBE_H
