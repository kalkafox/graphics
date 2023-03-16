#include "RenderObject.h"

PhyG::RenderObject::RenderObject() {
    s = new Shader(vertex_shader_location, fragment_shader_location);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        // handle error: glBindBuffer failed
        std::cout << glewGetErrorString(error) << std::endl;
    }
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(attribute_arr), attribute_arr, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 3*sizeof(GL_FLOAT), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

PhyG::RenderObject::~RenderObject() {
    delete s;
}

void PhyG::RenderObject::Render() {
    s->use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 4);
    glBindVertexArray(0);
}