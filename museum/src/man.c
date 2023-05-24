#include "man.h"

void init_man(Man* man)
{
    load_model(&(man->man), "assets/models/man.obj");
    man->man_texture_id = load_texture("assets/textures/Skull.jpg");
}

void render_man(Man* man)
{
	static float angle = 0.0f;
	
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, man->man_texture_id);
    glTranslatef( -5, -2.5, 1);
	glScalef(0.02, 0.02, 0.02);
	glRotated(angle, 0, 0, 1);  // Forgatás a Y tengely körül
    draw_model(&(man->man));
    glPopMatrix();
	
	//forgatás frissítése
	angle += 0.5f;
}