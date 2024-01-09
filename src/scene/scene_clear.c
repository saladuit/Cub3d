#include "libft.h"
#include "scene.h"

void scene_clear(t_scene *scene)
{
	if (scene->no_path)
		free(scene->no_path);
	if (scene->ea_path)
		free(scene->ea_path);
	if (scene->so_path)
		free(scene->so_path);
	if (scene->we_path)
		free(scene->we_path);
	if (scene->map)
		ft_free_str_table(&scene->map);
}
