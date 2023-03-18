//
// Created by Brandon Boudreaux on 3/16/23.
//

#include "Triangle.h"

PhyG::Triangle::Triangle(std::string vertex_shader_location, std::string fragment_shader_location) : PhyG::RenderObject(vertex_shader_location, fragment_shader_location){
    // We don't need the EBO for this..
    UnbindEBO();

    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

    //GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), (void*)0);
    glEnableVertexAttribArray(0);

    UnbindVAO();
    UnbindVBO();
    UnbindEBO();
}

void PhyG::Triangle::Render(){
    RenderObject::Render();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    UnbindVAO();
}