//
// Created by guilherme on 08/01/21.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H


// Include GLEW
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>
#include "common/shader.hpp"
// GLM header file
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;
// shaders header file
#include "common/shader.hpp"
#include "Board.h"

class Game {
public:
    //OS ÚNICOS MÉTODOS PÚBLICOS
    Game(int HEIGHT, int WIDTH, GLFWwindow *window);

    void Start();

private:
    int HEIGHT;
    int WIDTH;
    GLuint programID;
    GLuint VertexArrayID;

    GLFWwindow *window;
    Board gameBoard;


    GLuint block_vertex_buffer;
    GLuint block_color_buffers[8]{};



    void tick();

    bool listenMoves();

    void render();

    void draw();

    void transferDataToGPUMemory(void);

    void cleanGPU();
};


#endif //TETRIS_GAME_H
