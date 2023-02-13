#ifndef PHY_GRAPHICS_SHADER_H
#define PHY_GRAPHICS_SHADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <GLFW/glfw3.h>

class Shader {
public:
    Shader( std::string vertex_path, std::string fragment_path );
    ~Shader();
    void use();

private:
    const char* vertex_code = "";
    const char* fragment_code = "";
    int program_id = -1;
};


#endif //PHY_GRAPHICS_SHADER_H
