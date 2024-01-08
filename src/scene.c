#include "scene.h"
#include "error.h"
#include "libft.h"

#include <stdbool.h>

static void set_scene_path(char **path, char *value)
{
	if (*path)
		free(*path);
	*path = ft_strdup(value);
	if (!*path)
		system_error_and_exit("ft_strdup in set_scene_path");
}

bool line_to_scene_value(t_scene *scene, char *line)
{
	char **identifier_value;

	identifier_value = ft_split(line, " ");
	if (!identifier_value)
		system_error_and_exit("ft_split in string_to_scene");
	if (!identifier_value[0] || !identifier_value[1])
		user_error_and_exit("Not enough values in one of the settings");
	if (identifier_value[2])
		user_error_and_exit("Too many values in one of the settings");
	if (ft_strncmp(identifier_value[0], "NO ", 3) == 0)
		set_scene_path(&scene->no_path, identifier_value[1]);
	else if (ft_strncmp(identifier_value[0], "EA ", 3) == 0)
		set_scene_path(&scene->ea_path, identifier_value[1]);
	else if (ft_strncmp(identifier_value[0], "SO ", 3) == 0)
		set_scene_path(&scene->so_path, identifier_value[1]);
	else if (ft_strncmp(identifier_value[0], "WE ", 3) == 0)
		set_scene_path(&scene->we_path, identifier_value[1]);
	else if (ft_strncmp(identifier_value[0], "F ", 2) == 0)
		string_to_rgb(identifier_value[1], &scene->floor);
	else if (ft_strncmp(identifier_value[0], "C ", 2) == 0)
		string_to_rgb(identifier_value[1], &scene->ceil);
	else
		return (false);
	return (true);
}

void clear_scene(t_scene *scene)
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
