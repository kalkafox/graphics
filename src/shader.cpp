#include "shader.h"

Shader::Shader( std::string vertex_path, std::string fragment_path ){
    // Load in the shader:
    std::ifstream vFile;
    std::ifstream fFile;
    std::stringstream vStream, fStream;

    vFile.exceptions( std::ifstream::failbit | std::ifstream::badbit );
    fFile.exceptions( std::ifstream::failbit | std::ifstream::badbit );

    try {
        vFile.open(vertex_path);
        fFile.open(fragment_path);

        vStream << vFile.rdbuf();
        fStream << fFile.rdbuf();

        fFile.close();
        vFile.close();
    }catch(std::ifstream::failure e){
        std::cout << "SHADER READ ERROR: " << e.what() << std::endl;
    }

    vertex_code = vStream.str().c_str();
    fragment_code = fStream.str().c_str();

    // Compile the shaders
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertex_code, NULL);
    glCompileShader(vertex);
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if(!success){
        std::cout << "There was a problem compiling the shader " << vertex_path << std::endl;
    }

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragment_code, NULL);
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if(!success){
        std::cout << "There was a problem compiling the shader " << fragment_path << std::endl;
    }

    program_id = glCreateProgram();
    glAttachShader(program_id, vertex);
    glAttachShader(program_id, fragment );
    glLinkProgram(program_id);
    glGetProgramiv(program_id, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(program_id, 512, NULL, infoLog);
        std::cout << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use(){
    glUseProgram(program_id);
}