
#include "error.h"
#include "libft.h"
#include "scene.h"

void set_scene_map(const char *string, t_scene *scene, size_t line_start)
{
	check_valid_map(string + line_start);
	scene->map = ft_split(string + line_start, "\n");
	if (!scene->map)
		system_error_and_exit("ft_split in string_to_scene");
	if (scene->map[0] == NULL)
		user_error_and_exit("No map found");
	scene->map = create_square_map(scene->map);
	// if (is_closed_map(scene->map) == false)
	// 	user_error_and_exit("Map is not closed");
}
