// Include standard headers
#include <stdio.h>
#include <stdlib.h>
// Include GLEW
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>

GLFWwindow *window;

// GLM header file
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

using namespace glm;

#include "common/shader.hpp"

#define WINDOW_H 800
#define WINDOW_W 600

#include "Board.h"
#include "Shape.h"
#include "Game.h"

//J para Jogo, M para menu
char state = 'J';

void setup();

void startGame();

void startState();

int main(void) {
    setup();
    startState();
}

//Diz se estamos no menu ou no jogo
void startState() {
    switch (state) {
        case 'J':
            startGame();
            break;
        case 'M':
            break;
    }

}


void setup() {

    // Initialise GLFW
    glfwInit();

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window
    window = glfwCreateWindow(800, 800, "Moving House in 2D ", NULL, NULL);

    // Create window context
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    glewInit();

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // White background
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

}


void startGame() {
    Game game = Game(WINDOW_H, WINDOW_W, window);
    game.Start();
}