#ifndef PHY_GRAPHICS_SHADER_H
#define PHY_GRAPHICS_SHADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "GL/glew.h"

class Shader {
public:
    Shader( std::string vertex_path, std::string fragment_path );
    ~Shader();
    void use();

private:
    int program_id;
};


#endif //PHY_GRAPHICS_SHADER_H
