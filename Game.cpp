
#include <cstdio>
#include <iostream>
#include "Game.h"
#include "Models.h"
#include "utils.h"


Game::Game(GLFWwindow *window) {
    gameBoard = Board();
    this->window = window;
}

void Game::Start() {

    transferDataToGPUMemory();
    // se devolver true é porque perdeu, se devolveu false é porque só quis voltar atrás
    bool perdeu = tick();
    glClear(GL_COLOR_BUFFER_BIT);
    if (perdeu) {
        printf("GAMEOVER");
        fflush(stdout);
        gameOverWait();
    }
    cleanGPU();
}

void Game::gameOverWait() {
    while (true) {

        glClear(GL_COLOR_BUFFER_BIT);

        char text[256];
        sprintf(text, "Perdeste Jacare. Pontos: %d", pontos);
        printText2DWithColor(text, 0, 300, 30, glm::vec3(0.0f, 0.0f, 0.0f));
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            cleanGPU();
            glfwSetWindowShouldClose(window, true);
            exit(0);
        }
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            glClear(GL_COLOR_BUFFER_BIT);
            cleanGPU();
            glfwSetWindowShouldClose(window, true);
            glfwDestroyWindow(window);
            return;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

bool Game::tick() {
    bool running = true;
    Shape shape = Shape();
    gameBoard.insertShape(&shape);

    while (running) {
        render();


        if (sleptTicks % 4 == 0) {
            running = listenMoves();
        }
        if (sleptTicks <= sleepTicks) {

            sleptTicks = sleptTicks + int(sqrt(pontos));
            continue;
        }
        sleptTicks = 0;
        if (!gameBoard.move_piece('D')) {
            vector<int> clearedRows = gameBoard.clearFullRows();
            if (pontos != pontos + clearedRows.size()) {
                pontos += clearedRows.size() * clearedRows.size();
                sleepTicks = sleepTicks - sqrt(pontos);
            }

            running = !gameBoard.currentShape->hasNegative();
            if (!running) {
                fflush(stdout);
                printf("FINISHING");
                return true;
            }
            shape = Shape();
            gameBoard.insertShape(&shape);
        }
    }
    return false;

}


void Game::render() {
    draw();
    glfwSwapBuffers(window);
    glfwPollEvents();
}


void Game::draw(void) {
    angulo += 0.0015f * pontos;
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    char text[256];
    sprintf(text, "Pontos: %d", pontos);


    printText2DWithColor(text, 300, 10, 20, glm::vec3(0.5f, 0, 0.5f));


    glUseProgram(programID);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(glm::sin(angulo) * pontos), glm::vec3(1, 1, 2));
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::lookAt(
            //posição da câmara a olhar para o ponto
            glm::vec3(10, -20, 60), // Camera is at (4,3,-3), in World Space
            glm::vec3(-1 * glm::sin(angulo * pontos), -1, -1000), // and looks at the origin
            glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    // Our ModelViewProjection : multiplication of our 3 matrices
    glm::mat4 mvp = projection * view * model;

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, block_texture);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    unsigned int matrix = glGetUniformLocation(programID, "mvp");
    unsigned int m = glGetUniformLocation(programID, "trans");

    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


    glm::mat4 trans = glm::mat4(1.0);

    float zoom = 1.5;
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(zoom, zoom, zoom));
    glUniformMatrix4fv(m, 1, GL_FALSE, &(scale * trans)[0][0]);


    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, block_vertex_buffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);

    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, block_texture);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);


    vector<vector<int>> currentState = gameBoard.getcurrentState();

    for (int i = 0; i < currentState.size(); i++) {
        for (int j = 0; j < currentState.at(i).size(); j++) {

            if (currentState.at(i).at(j) == 0) continue;
            glEnableVertexAttribArray(1);
            glBindBuffer(GL_ARRAY_BUFFER, block_color_buffers[currentState.at(i).at(j) - 1]);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);

            trans = glm::translate(scale, vec3((float) j + 1 + zoom, (float) -(i + 1 + zoom), 0.0f));
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

                trans = glm::translate(scale, vec3((float) j + zoom, (float) -i - zoom, 0.0f));
                glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);

                glDrawArrays(GL_TRIANGLES, 0, 6); // 3 indices starting at 0 -> 1 triangle
            } else {
                if (j == 0 || j == 11) {
                    glEnableVertexAttribArray(1);
                    glBindBuffer(GL_ARRAY_BUFFER, block_color_buffers[7]);
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *) 0);

                    trans = glm::translate(scale, vec3((float) j + zoom, -((float) i + zoom), 0.0f));
                    glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);

                    glDrawArrays(GL_TRIANGLES, 0, 6); // 3 indices starting at 0 -> 1 triangle
                }
            }
        }
    }


    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);


}

bool Game::listenMoves() {
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS && rotateFlag) {
        gameBoard.rotate_piece();
        rotateFlag = false;
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_RELEASE) {
        rotateFlag = true;
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
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
        glfwDestroyWindow(window);
        return false;
    }


    return true;
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

    glGenTextures(1, &block_texture);
    glBindTexture(GL_TEXTURE_2D, block_texture);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char *data = stbi_load("bloco_fixe_3.png", &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

    } else {
        std::cout << "Failed to load texture" << std::endl;
    }

    stbi_image_free(data);

    initText2D("Arial.dds");

}

void Game::cleanGPU() {
    glDeleteBuffers(1, &block_vertex_buffer);
    for (int i = 0; i < 8; i++) {
        glDeleteBuffers(1, &block_color_buffers[i]);
    }
    glDeleteVertexArrays(1, &VertexArrayID);
    glDeleteProgram(programID);


}