#ifndef PHY_GRAPHICS_PRIMITIVES_H
#define PHY_GRAPHICS_PRIMITIVES_H

//#include "GL/glew.h"
#include "glad/glad.h"

namespace PhyG::Primitives{
    namespace Cube {
        const GLfloat vertices[72] = {
                // Front face
                -1.0f, -1.0f, 1.0f,  // Bottom left
                1.0f, -1.0f, 1.0f,  // Bottom right
                1.0f, 1.0f, 1.0f,  // Top right
                -1.0f, 1.0f, 1.0f,  // Top left

                // Back face
                -1.0f, -1.0f, -1.0f,  // Bottom left
                1.0f, -1.0f, -1.0f,  // Bottom right
                1.0f, 1.0f, -1.0f,  // Top right
                -1.0f, 1.0f, -1.0f,  // Top left

                // Top face
                -1.0f, 1.0f, 1.0f,  // Front left
                1.0f, 1.0f, 1.0f,  // Front right
                1.0f, 1.0f, -1.0f,  // Back right
                -1.0f, 1.0f, -1.0f,  // Back left

                // Bottom face
                -1.0f, -1.0f, 1.0f,  // Front left
                1.0f, -1.0f, 1.0f,  // Front right
                1.0f, -1.0f, -1.0f,  // Back right
                -1.0f, -1.0f, -1.0f,  // Back left

                // Right face
                1.0f, -1.0f, 1.0f,  // Front bottom
                1.0f, 1.0f, 1.0f,  // Front top
                1.0f, 1.0f, -1.0f,  // Back top
                1.0f, -1.0f, -1.0f,  // Back bottom

                // Left face
                -1.0f, -1.0f, 1.0f,  // Front bottom
                -1.0f, 1.0f, 1.0f,  // Front top
                -1.0f, 1.0f, -1.0f,  // Back top
                -1.0f, -1.0f, -1.0f   // Back bottom
        };

        const GLuint indices[36] = {
                0, 1, 2, 0, 2, 3,    // Front face
                4, 5, 6, 4, 6, 7,    // Back face
                8, 9, 10, 8, 10, 11,  // Top face
                12, 13, 14, 12, 14, 15, // Bottom face
                16, 17, 18, 16, 18, 19, // Right face
                20, 21, 22, 20, 22, 23  // Left face
        };
    }

    namespace Triangle{
        const GLfloat vertices[] = {
                0.0f,  0.5f,  0.0f,
                0.5f, -0.5f,  0.0f,
                -0.5f, -0.5f,  0.0f
        };
    }
}

#endif //PHY_GRAPHICS_PRIMITIVES_H
