//
// Created by Brandon Boudreaux on 3/16/23.
//

#include "Triangle.h"

PhyG::Triangle::Triangle(std::string vertex_shader_location, std::string fragment_shader_location) : PhyG::RenderObject(vertex_shader_location, fragment_shader_location){
    UnbindEBO();
}