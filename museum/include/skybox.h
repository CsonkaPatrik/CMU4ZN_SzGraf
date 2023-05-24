#ifndef SKYBOX_H
#define SKYBOX_H

#include <obj/model.h>
#include <GL/gl.h>
#include <obj/load.h>
#include <obj/draw.h>
#include "texture.h"

typedef struct Skybox
{
    GLuint skyBox_texture_id;
} Skybox;

void render_skyBox(Skybox* skyBox);

#endif