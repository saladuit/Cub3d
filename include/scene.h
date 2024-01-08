#ifndef SCENE_H
#define SCENE_H

#include "rgb.h"
#include <stdbool.h>

typedef struct s_scene
{
	char *no_path;
	char *so_path;
	char *we_path;
	char *ea_path;
	t_rgb floor;
	t_rgb ceil;
	char **map;
} t_scene;

void clear_scene(t_scene *scene);
bool line_to_scene_value(t_scene *scene, char *string);

#endif
