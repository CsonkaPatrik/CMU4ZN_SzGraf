#ifndef MAN_H
#define MAN_H

#include <obj/model.h>
#include <GL/gl.h>
#include <obj/load.h>
#include <obj/draw.h>
#include "texture.h"

typedef struct Man
{
    Model man;
    GLuint man_texture_id;
} Man;

void init_man(Man* man);
void render_man(Man* man);

#endif