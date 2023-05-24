#include "door.h"

void init_door(Door* door)
{
    load_model(&(door->door), "assets/models/door.obj");
    door->door_texture_id = load_texture("assets/textures/door.jpg");
}

void render_door(Door* door)
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, door->door_texture_id);
    glTranslatef( 0, 10, 0);
	glScalef(0.013, 0.013, 0.013);
	glRotated(270, 1, 0, 0);
    draw_model(&(door->door));
    glPopMatrix();
}