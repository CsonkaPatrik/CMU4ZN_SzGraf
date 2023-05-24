#include "scene.h"
#include "app.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <SDL2/SDL.h>
#include <math.h>


void init_scene(Scene* scene)
{
	init_skyBox(&(scene->skyBox));
	init_ground(&(scene->ground));
	init_man(&(scene->man));
	init_statue1(&(scene->statue1));
	init_statue2(&(scene->statue2));
	init_plane(&(scene->plane));
	init_door(&(scene->door));
	
    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 0.0;
	
	scene->brightness = 0.0f;
	scene->shelp = 0;
	
	scene->controlLight[0] = 1.0f;
    scene->controlLight[1] = 1.0f;
    scene->controlLight[2] = 1.0f;
	
}

void set_lighting(Scene* scene)
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    float ambient_light[] = { scene->controlLight[0], scene->controlLight[1], scene->controlLight[0], 1.0 }; // Fehér ambiens szín
    float diffuse_light[] = { scene->controlLight[0], scene->controlLight[1], scene->controlLight[0], 1.0f }; // Fehér diffúz szín
    float specular_light[] = { scene->controlLight[0], scene->controlLight[1], scene->controlLight[0], 1.0f }; // Fehér spekuláris szín
    float position[] = { 0.0f, 1.0f, 0.0f, 0.0f }; // Fényforrás pozíciója

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene, double time)
{
	scene->controlLight[0] += scene->brightness * time;
    scene->controlLight[1] += scene->brightness * time;
    scene->controlLight[2] += scene->brightness * time;
    scene->controlLight[3] += scene->brightness * time;
}

void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting(scene);
	render_ground(&(scene->ground));
	render_skyBox(&(scene->skyBox));
	render_man(&(scene->man));
	render_statue1(&(scene->statue1));
	render_statue2(&(scene->statue2));
	render_plane(&(scene->plane));
	render_door(&(scene->door));
	
    glEnd();
}

void setBrightness(Scene *scene, double brightness) {
    scene->brightness = brightness;
}

void help(Scene *scene)
{
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, load_texture("assets/textures/help.jpg"));

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3d(-2, 1.5, -3);
    glTexCoord2f(1, 0);
    glVertex3d(2, 1.5, -3);
    glTexCoord2f(1, 1);
    glVertex3d(2, -1.5, -3);
    glTexCoord2f(0, 1);
    glVertex3d(-2, -1.5, -3);
    glEnd();
}