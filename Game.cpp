//
// Created by guilherme on 08/01/21.
//


#include <cstdio>
#include <iostream>
#include "Game.h"
#include "Models.h"
#include "utils.h"

Game::Game(int HEIGHT, int WIDTH, GLFWwindow *window) {
    gameBoard = Board();
    this->HEIGHT = HEIGHT;
    this->WIDTH = WIDTH;
    this->window = window;
}

void Game::Start() {

    transferDataToGPUMemory();
    tick();
    cleanGPU();

}

void Game::tick() {
    bool running = true;
    Shape shape = Shape();
    gameBoard.insertShape(&shape);

    while (running) {
        render();
        listenMoves();
        if (!gameBoard.move_piece('D')) {
            gameBoard.clearFullRows();
            running = !gameBoard.currentShape->hasNegative();
            shape = Shape();
            gameBoard.insertShape(&shape);
            fflush(stdout);
            gameBoard.currentShape->printCoordinates();
        }
        gameBoard.clearFullRows();
        sleep(0.1f);
    }

}


void Game::render() {
    draw();
    glfwSwapBuffers(window);
    glfwPollEvents();
}


void Game::draw(void) {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Use our shader
    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-40.0f, 40.0f, -40.0f, 40.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    unsigned int matrix = glGetUniformLocation(programID, "mvp");
    unsigned int m = glGetUniformLocation(programID, "trans");

    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


    glm::mat4 trans = glm::mat4(1.0);
    glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);


    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, block_vertex_buffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);


    vector<vector<int>> currentState = gameBoard.getcurrentState();

    for (int i = 0; i < currentState.size(); i++) {
        for (int j = 0; j < currentState.at(i).size(); j++) {

            if (currentState.at(i).at(j) == 0) continue;
            glEnableVertexAttribArray(1);
            glBindBuffer(GL_ARRAY_BUFFER, block_color_buffers[currentState.at(i).at(j) - 1]);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);

            trans = glm::translate(mat4(1), vec3((float) j + 1, (float) -(i + 1), 0.0f));
            glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);

            glDrawArrays(GL_TRIANGLES, 0, 6); // 3 indices starting at 0 -> 1 triangle
        }
    }
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 12; j++) {
            if (i == 0 || i == 21) {
                glEnableVertexAttribArray(1);
                glBindBuffer(GL_ARRAY_BUFFER, block_color_buffers[7]);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);

                trans = glm::translate(mat4(1), vec3((float) j, (float) -i, 0.0f));
                glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);

                glDrawArrays(GL_TRIANGLES, 0, 6); // 3 indices starting at 0 -> 1 triangle
            } else {
                if (j == 0 || j == 11) {
                    glEnableVertexAttribArray(1);
                    glBindBuffer(GL_ARRAY_BUFFER, block_color_buffers[7]);
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);

                    trans = glm::translate(mat4(1), vec3((float) j, (float) -i, 0.0f));
                    glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);

                    glDrawArrays(GL_TRIANGLES, 0, 6); // 3 indices starting at 0 -> 1 triangle
                }
            }
        }
    }


    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);


}

//incluir moves nos Ifs
//remover bools
bool Game::listenMoves() {
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        gameBoard.currentShape->rotateShape(1);
    }

    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        gameBoard.move_piece('D');
    }

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        gameBoard.move_piece('R');
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        gameBoard.move_piece('L');
    }
}

void Game::transferDataToGPUMemory(void) {


    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

    glGenBuffers(1, &block_vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, block_vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(block_vertex_data), block_vertex_data, GL_STATIC_DRAW);

    for (int i = 0; i < 8; i++) {
        glGenBuffers(1, &block_color_buffers[i]);
        glBindBuffer(GL_ARRAY_BUFFER, block_color_buffers[i]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(block_color_data[i]), block_color_data[i], GL_STATIC_DRAW);
    }
}

void Game::cleanGPU() {
    glDeleteBuffers(1, &block_vertex_buffer);
    for (int i = 0; i < 8; i++) {
        glDeleteBuffers(1, &block_color_buffers[i]);
    }
    glDeleteVertexArrays(1, &VertexArrayID);
    glDeleteProgram(programID);


}