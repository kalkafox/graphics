#include "RenderObject.h"

PhyG::RenderObject::RenderObject(std::string vertex_shader_location, std::string fragment_shader_location) {
    s = std::make_unique<Shader>(vertex_shader_location, fragment_shader_location);

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

PhyG::RenderObject::RenderObject() {
    s = std::make_unique<Shader>("../shaders/base.vert", "../shaders/base.frag");

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

PhyG::RenderObject::~RenderObject() {}

void PhyG::RenderObject::Render() {
    UseShader();
    BindVAO();
}