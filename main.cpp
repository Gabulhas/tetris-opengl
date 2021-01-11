#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLFWwindow *window;
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION

#define WINDOW_H 800
#define WINDOW_W 600

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
    window = glfwCreateWindow(800, 800, "Tretis", NULL, NULL);

    // Create window context
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    glewInit();

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // White background
    glClearColor(0.1f, 0.1f, 0.1f, 0.1f);

}


void startGame() {
    Game game = Game(WINDOW_H, WINDOW_W, window);
    game.Start();
}