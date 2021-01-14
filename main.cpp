#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLFWwindow *window;

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION

#define WINDOW_H 800
#define WINDOW_W 800

#include "Game.h"
#include "Models.h"

GLuint VertexArrayID;

//J para Jogo, M para menu
char state = 'M';
int selectedOption = 0;
bool showMenu = true;
bool pressedUp = false;
bool pressedDown = false;

void setup();

void getLogo();

void startGame();

bool listenKeys();

void startState();

void drawMenu();

void Menu();

void cleanGPU();

int main(void) {
    startState();
}

void Menu() {
    initText2D("Holstein.DDS");
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    while (showMenu) {
        drawMenu();
        if (listenKeys()) {
            state = 'J';
            cleanGPU();
            return;
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

bool listenKeys() {
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS && !pressedUp) {
        pressedUp = true;
        selectedOption = 0;
    } else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS && !pressedDown) {
        pressedDown = true;
        selectedOption = 1;
    } else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_RELEASE) {
        pressedUp = false;
    } else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_RELEASE) {
        pressedDown = false;
    }
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
        if (selectedOption == 1) {
            cleanGPU();
            glfwSetWindowShouldClose(window, true);
            exit(0);
        } else {
            return true;

        }
    }
    return false;


}

//Diz se estamos no menu ou no jogo
void startState() {
    while (true) {

        switch (state) {
            case 'J':
                startGame();
                state = 'M';
                break;
            case 'M':
                setup();
                Menu();
                break;
        }
    }

}

void drawMenu() {


    glClear(GL_COLOR_BUFFER_BIT);

    if (selectedOption == 0) {
        printText2DWithColor("Start", 250, 400, 60, glm::vec3(1.0f, 0.0f, 0.0f));
        printText2DWithColor("Exit", 250, 300, 60, glm::vec3(0.196f, 0.196f, 0.196f));
    } else {
        printText2DWithColor("Start", 250, 400, 60, glm::vec3(0.196f, 0.196f, 0.196f));
        printText2DWithColor("Exit", 250, 300, 60, glm::vec3(1.0f, 0.0f, 0.0f));
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
    window = glfwCreateWindow(WINDOW_W, WINDOW_H, "Tretis", NULL, NULL);

    // Create window context
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    glewInit();

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // White background
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

}


void cleanGPU() {
    cleanupText2D();
}


void startGame() {
    Game game = Game(window);
    game.Start();
    state = 'M';
    startState();
}

