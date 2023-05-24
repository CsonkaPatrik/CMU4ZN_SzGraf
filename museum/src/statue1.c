#include "statue1.h"

void init_statue1(Statue1* statue1)
{
    load_model(&(statue1->statue1), "assets/models/statue1.obj");
    statue1->statue1_texture_id = load_texture("assets/textures/statue1.jpg");
}

void render_statue1(Statue1* statue1)
{
    static float angle = 0.0f;  // Szög változó a forgatáshoz

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, statue1->statue1_texture_id);
    glTranslatef( -5, 0, 0); 
	glScalef(0.005, 0.005, 0.005);  
	glRotated(angle, 0, 0, 1);  // Forgatás a Y tengely körül
    draw_model(&(statue1->statue1));
    glPopMatrix();

    //forgatás frissítése
    angle += 0.5f;  // Forgatás sebessége
}