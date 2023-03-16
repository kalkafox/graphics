#include "RenderObject.h"

PhyG::RenderObject::RenderObject() {
    s = new Shader(vertex_shader_location, fragment_shader_location);
    vao = glGenVertex
}

PhyG::RenderObject::~RenderObject() {
    delete s;
}

void PhyG::RenderObject::Render() {
    s->use();
}