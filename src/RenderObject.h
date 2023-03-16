#ifndef PHY_GRAPHICS_RENDEROBJECT_H
#define PHY_GRAPHICS_RENDEROBJECT_H

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "shader.h"

namespace PhyG{
    class RenderObject {
    public:
        RenderObject();
        ~RenderObject();
        void Render();

    private:
        std::string vertex_shader_location = "../shaders/base.vert";
        std::string fragment_shader_location = "../shaders/base.frag";
        Shader *s;
        const double attribute_arr[12] = {
                1.0, 1.0, 1.0,
                -1.0, 1.0, 1.0,
                -1.0, -1.0, 1.0,
                1.0, -1.0, 1.0
        };
        unsigned int vao;
        unsigned int vbo;
    };
}

#endif //PHY_GRAPHICS_RENDEROBJECT_H
