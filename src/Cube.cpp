#include "Cube.h"

PhyG::Cube::Cube(std::string vertex_shader_location, std::string fragment_shader_location) : RenderObject(vertex_shader_location, fragment_shader_location){
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indis), indis, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

PhyG::Cube::~Cube(){
    RenderObject::~RenderObject();
}