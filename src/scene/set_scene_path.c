#include "error.h"
#include "libft.h"
#include "scene.h"

void set_scene_path(char **path, char *value)
{
	if (*path)
		free(*path);
	*path = ft_strdup(value);
	if (!*path)
		system_error_and_exit("ft_strdup in set_scene_path");
}
