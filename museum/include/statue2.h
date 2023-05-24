#ifndef STATUE2_H
#define STATUE2_H

#include <obj/model.h>
#include <GL/gl.h>
#include <obj/load.h>
#include <obj/draw.h>
#include "texture.h"

typedef struct Statue2
{
    Model statue2;
    GLuint statue2_texture_id;
} Statue2;

void init_statue2(Statue2* statue2);
void render_statue2(Statue2* statue2);

#endif