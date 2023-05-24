#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "ground.h"
#include "skybox.h"
#include "man.h"
#include "statue1.h"
#include "statue2.h"
#include "plane.h"
#include "door.h"

#include <math.h>

#include <obj/model.h>


typedef struct Scene
{
    Material material;
    GLuint texture_id;
	
	Ground ground;
	GLuint skyBox;
	Man man;
	Statue1 statue1;
	Statue2 statue2;
	Plane plane;
	Door door;
	
	float controlLight[3];
	float brightness;
	int shelp;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene, double time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

void setBrightness(Scene *scene, double brightness);

void shelp(Scene *scene);

#endif /* SCENE_H */
