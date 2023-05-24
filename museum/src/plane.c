#include "plane.h"

void init_plane(Plane* plane)
{
    load_model(&(plane->plane), "assets/models/plane.obj");
    plane->plane_texture_id = load_texture("assets/textures/plane.jpg");
}

void render_plane(Plane* plane)
{
    static float angle = 0.0f;  // Szög változó a forgatáshoz

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, plane->plane_texture_id);
	glScalef(0.5, 0.5, 0.5);  
	glRotated(angle, 0, 0, 1);	// Forgatás a Y tengely körül
    glTranslatef( 5, 10, 7);
	draw_model(&(plane->plane));
    glPopMatrix();

    //forgatás frissítése
    angle += 0.5f;  // Forgatás sebessége
}