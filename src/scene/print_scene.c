
#include "scene.h"
#include <stdio.h>

void print_scene(t_scene *scene)
{
	printf("no_path: %s\n", scene->no_path);
	printf("ea_path: %s\n", scene->ea_path);
	printf("so_path: %s\n", scene->so_path);
	printf("we_path: %s\n", scene->we_path);
	printf("floor: r%d, g%d, b%d\n", scene->floor.r, scene->floor.g,
		   scene->floor.b);
	printf("ceil: r%d, g%d, b%d\n", scene->ceil.r, scene->ceil.g,
		   scene->ceil.b);
	printf("map:\n");
	if (!scene->map)
		return;
	for (size_t i = 0; scene->map[i]; i++)
		printf("%s\n", scene->map[i]);
}
