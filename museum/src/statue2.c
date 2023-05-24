#include "statue2.h"

void init_statue2(Statue2* statue2)
{
    load_model(&(statue2->statue2), "assets/models/statue2.obj");
    statue2->statue2_texture_id = load_texture("assets/textures/statue2.jpg");
}

void render_statue2(Statue2* statue2)
{
    static float angle = 0.0f;  // Szög változó a forgatáshoz

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, statue2->statue2_texture_id);
    glTranslatef( -5, 2.5, 0); 
	glScalef(0.015, 0.015, 0.015); 
	glRotated(angle, 0, 0, 1);  // Forgatás a Y tengely körül
    draw_model(&(statue2->statue2));
    glPopMatrix();

    //forgatás frissítése
    angle += 0.5f;  // Forgatás sebessége
}