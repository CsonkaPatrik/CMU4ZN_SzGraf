#ifndef STATUE1_H
#define STATUE1_H

#include <obj/model.h>
#include <GL/gl.h>
#include <obj/load.h>
#include <obj/draw.h>
#include "texture.h"

typedef struct Statue1
{
    Model statue1;
    GLuint statue1_texture_id;
} Statue1;

void init_statue1(Statue1* statue1);
void render_statue1(Statue1* statue1);

#endif