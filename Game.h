#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H


// Include GLEW
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>
#include "common/shader.hpp"
#include "common/stb_image.h"
#include "common/text2D.hpp"

// GLM header file
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;
// shaders header file

#include "Board.h"

class Game {
public:
    //OS ÚNICOS MÉTODOS PÚBLICOS
    Game(GLFWwindow *window);

    void Start();

private:
    GLuint programID;
    GLuint VertexArrayID;

    GLFWwindow *window;
    Board gameBoard;


    GLuint block_vertex_buffer;
    GLuint block_color_buffers[8]{};
    GLuint block_texture;

    int pontos = 1;
    float angulo = 0;

    int sleepTicks = 150;
    int sleptTicks = 0;

    bool rotateFlag = true;
    bool tick();

    bool listenMoves();

    void render();

    void draw();

    void transferDataToGPUMemory(void);

    void cleanGPU();

    void gameOverWait();
};


#endif //TETRIS_GAME_H
