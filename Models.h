//
// Created by guilherme on 08/01/21.
//

#ifndef TETRIS_MODELS_H
#define TETRIS_MODELS_H

#include <GL/glew.h>

static const GLfloat block_vertex_data[] = {
        0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
};

static const GLfloat block_texture_points[] = {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,

};

// One color for each vertex. They were generated randomly.
static const GLfloat block_color_data[8][18] = {
        //vermelho
        {
                1.0f,   0.0f,   0.0f,
                1.0f,   0.0f,   0.0f,
                1.0f,   0.0f,   0.0f,
                1.0f,   0.0f,   0.0f,
                1.0f,   0.0f,   0.0f,
                1.0f,   0.0f,   0.0f,
        },
        //verde
        {
                0.0f,   1.0f,   0.0f,
                0.0f,   1.0f,   0.0f,
                0.0f,   1.0f,   0.0f,
                0.0f,   1.0f,   0.0f,
                0.0f,   1.0f,   0.0f,
                0.0f,   1.0f,   0.0f,
        },
        //azul
        {
                0.0f,   0.0f,   1.0f,
                0.0f,   0.0f,   1.0f,
                0.0f,   0.0f,   1.0f,
                0.0f,   0.0f,   1.0f,
                0.0f,   0.0f,   1.0f,
                0.0f,   0.0f,   1.0f,
        },
        //laranja
        {
                1.0f,   0.588f, 0.0f,
                1.0f,   0.588f, 0.0f,
                1.0f,   0.588f, 0.0f,
                1.0f,   0.588f, 0.0f,
                1.0f,   0.588f, 0.0f,
                1.0f,   0.588f, 0.0f,
        },
        //lima
        {
                0.745f, 0.98f,  0.0f,
                0.745f, 0.98f,  0.0f,
                0.745f, 0.98f,  0.0f,
                0.745f, 0.98f,  0.0f,
                0.745f, 0.98f,  0.0f,
                0.745f, 0.98f,  0.0f,
        },
        //roxo
        {
                0.667f, 0.0f,   1.0f,
                0.667f, 0.0f,   1.0f,
                0.667f, 0.0f,   1.0f,
                0.667f, 0.0f,   1.0f,
                0.667f, 0.0f,   1.0f,
                0.667f, 0.0f,   1.0f,
        },
        //amarelo
        {
                1.0f,   1.0f,   0.0f,
                1.0f,   1.0f,   0.0f,
                1.0f,   1.0f,   0.0f,
                1.0f,   1.0f,   0.0f,
                1.0f,   1.0f,   0.0f,
                1.0f,   1.0f,   0.0f,
        },
        {
                0.0f,   0.0f,   0.0f,
                0.0f,   0.0f,   0.0f,
                0.0f,   0.0f,   0.0f,
                0.0f,   0.0f,   0.0f,
                0.0f,   0.0f,   0.0f,
                0.0f,   0.0f,   0.0f,
        },

};

static const GLfloat logo_vertex_data[] = {
        350, 350, 350,
        400, 350, 350,
        400, 400, 350,
        350, 350, 350,
        400, 400, 350,
        350, 400, 350,
};
static const GLfloat logo_color_data[] =
        {
                1.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 0.0f,
                1.0f, 1.0f, 0.0f,
        };

#endif //TETRIS_MODELS_H
