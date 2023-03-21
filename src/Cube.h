//
// Created by Brandon Boudreaux on 3/16/23.
//

#ifndef PHY_GRAPHICS_CUBE_H
#define PHY_GRAPHICS_CUBE_H

#include "RenderObject.h"
#include "primitives.h"
//#include "GL/glew.h"
#include "glad/glad.h"

#define verts PhyG::Primitives::Cube::vertices
#define indis PhyG::Primitives::Cube::indices

namespace PhyG{
    class Cube : public PhyG::RenderObject{
    public:
        Cube(std::string vertex_shader_location, std::string fragment_shader_location);
        ~Cube();
        void Render();
    };
}


#endif //PHY_GRAPHICS_CUBE_H
