#ifndef DOOR_H
#define DOOR_H

#include <obj/model.h>
#include <GL/gl.h>
#include <obj/load.h>
#include <obj/draw.h>
#include "texture.h"

typedef struct Door
{
    Model door;
    GLuint door_texture_id;
} Door;

void init_door(Door* door);
void render_door(Door* door);

#endif