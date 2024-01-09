#include "scene.h"

void string_to_scene(char *string, t_scene *scene)
{
	size_t line_start = 0;
	line_start = set_scene_elements(string, scene);
	set_scene_map(string, scene, line_start);
}
