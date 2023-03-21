#ifndef PHY_GRAPHICS_SHADER_H
#define PHY_GRAPHICS_SHADER_H

#include <iostream>
#include <fstream>
#include <sstream>
//#include "GL/glew.h"
#include "glad/glad.h"

class Shader {
public:
    Shader( std::string vertex_path, std::string fragment_path );
    ~Shader();
    void Use();
    void SetUniform4f(std::string name, GLfloat v1, GLfloat v2, GLfloat v3, GLfloat v4 );

private:
    int program_id;
};


#endif //PHY_GRAPHICS_SHADER_H
