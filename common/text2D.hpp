#ifndef TEXT2D_HPP
#define TEXT2D_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
void initText2D(const char * texturePath);
void printText2D(const char * text, int x, int y, int size);
void printText2DWithColor(const char * text, int x, int y, int size, glm::vec3 colors);
void cleanupText2D();

#endif