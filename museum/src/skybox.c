#include "skybox.h"

void init_skyBox(Skybox* skyBox)
{
    skyBox->skyBox_texture_id = load_texture("assets/textures/sky.jpg");
}

void render_skyBox(Skybox* skyBox)
{
    float size = 10.0f;
	float offsetX = 0.0f;
    float offsetY = 0.0f; // Az eltolás mértéke
	float offsetZ = -3.0f;
	glDepthFunc(GL_LESS);
    glBindTexture(GL_TEXTURE_2D, skyBox->skyBox_texture_id);
	glBegin(GL_QUADS);
	
    // Elülső oldal
    glTexCoord2f(1, 1);
    glVertex3f(-size + offsetX, -size + offsetY, -size + offsetZ);

    glTexCoord2f(1, 0);
    glVertex3f(-size + offsetX, -size + offsetY, size + offsetZ);

    glTexCoord2f(0, 0);
    glVertex3f(size + offsetX, -size + offsetY, size + offsetZ);

    glTexCoord2f(0, 1);
    glVertex3f(size + offsetX, -size + offsetY, -size + offsetZ);

    // Hátsó oldal
    glTexCoord2f(1, 1);
    glVertex3f(-size + offsetX, size + offsetY, -size + offsetZ);

    glTexCoord2f(1, 0);
    glVertex3f(-size + offsetX, size + offsetY, size + offsetZ);

    glTexCoord2f(0, 0);
    glVertex3f(size + offsetX, size + offsetY, size + offsetZ);

    glTexCoord2f(0, 1);
    glVertex3f(size + offsetX, size + offsetY, -size + offsetZ);

    // Bal oldal
    glTexCoord2f(1, 1);
    glVertex3f(-size + offsetX, -size + offsetY, -size + offsetZ);

    glTexCoord2f(1, 0);
    glVertex3f(-size + offsetX, -size + offsetY, size + offsetZ);

    glTexCoord2f(0, 0);
    glVertex3f(-size + offsetX, size + offsetY, size + offsetZ);

    glTexCoord2f(0, 1);
    glVertex3f(-size + offsetX, size + offsetY, -size + offsetZ);

    // Jobb oldal
    glTexCoord2f(1, 1);
    glVertex3f(size + offsetX, -size + offsetY, -size + offsetZ);

    glTexCoord2f(1, 0);
    glVertex3f(size + offsetX, -size + offsetY, size + offsetZ);

    glTexCoord2f(0, 0);
    glVertex3f(size + offsetX, size + offsetY, size + offsetZ);

    glTexCoord2f(0, 1);
    glVertex3f(size + offsetX, size + offsetY, -size + offsetZ);

    // felső oldal
    glTexCoord2f(1, 1);
    glVertex3f(-size + offsetX, -size + offsetY, size + offsetZ);

    glTexCoord2f(1, 0);
    glVertex3f(-size + offsetX, size + offsetY, size + offsetZ);

    glTexCoord2f(0, 0);
    glVertex3f(size + offsetX, size + offsetY, size + offsetZ);

    glTexCoord2f(0, 1);
    glVertex3f(size + offsetX, -size + offsetY, size + offsetZ);

    glEnd();
}
