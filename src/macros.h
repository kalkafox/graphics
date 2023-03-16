//
// Created by Brandon Boudreaux on 3/16/23.
//

#ifndef PHY_GRAPHICS_MACROS_H
#define PHY_GRAPHICS_MACROS_H

#define  GL_ERROR_CHECK() GLenum error = glGetError(); if (error != GL_NO_ERROR) { std::cerr << glewGetErrorString(error) << std::endl;}

#endif //PHY_GRAPHICS_MACROS_H
