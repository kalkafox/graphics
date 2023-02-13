#ifndef CONFIG
#define CONFIG
#define WINDOW_NAME "Graphics Template"
#define WINDOW_HEIGHT 1024
#define WINDOW_WIDTH 800
#define DARK_COLORS
#define DEBUG

#ifdef __APPLE__
#define GLSL_VERSION "#version 150"
#else
#define GLSL_VERSION "#version 130"
#endif
#endif