#ifndef PLANE_H
#define PLANE_H

#include <obj/model.h>
#include <GL/gl.h>
#include <obj/load.h>
#include <obj/draw.h>
#include "texture.h"

typedef struct Plane
{
    Model plane;
    GLuint plane_texture_id;
} Plane;

void init_plane(Plane* plane);
void render_plane(Plane* plane);

#endif