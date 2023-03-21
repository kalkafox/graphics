#include "Cube.h"

PhyG::Cube::Cube(std::string vertex_shader_location, std::string fragment_shader_location) : RenderObject(vertex_shader_location, fragment_shader_location){
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indis), indis, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), (void*)0);
    glEnableVertexAttribArray(0);

    UnbindVAO();
    UnbindEBO();
    UnbindVBO();
}

PhyG::Cube::~Cube(){
    RenderObject::~RenderObject();
}

void PhyG::Cube::Render() {
    RenderObject::Render();
    //GLenum mode, GLsizei count, GLenum type, const void *indices
    glDrawElements(GL_TRIANGLES, 35, GL_UNSIGNED_INT, 0);
    UnbindVAO();
}