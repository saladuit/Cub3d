#include "error.h"
#include "libft.h"
#include "scene.h"

static bool create_scene_element_attempt(char *string, t_scene *scene,
										 size_t line_start, size_t len)
{
	char *line;

	line = ft_substr(string, line_start, len - 1);
	if (!line)
		system_error_and_exit("ft_substr in string_to_scene");
	if (line_to_scene_element(scene, line) == false)
	{
		free(line);
		return (false);
	}
	free(line);
	return (true);
}

size_t set_scene_elements(char *string, t_scene *scene)
{
	size_t i = 0;
	size_t line_start = 0;
	size_t len = 0;

	while (string[i])
	{
		if (string[i] == '\n')
		{
			if (len <= 1)
				line_start++;
			else if (string[i + 1] == ' ' ||
					 create_scene_element_attempt(string, scene, line_start,
												  len) == false)
				break;
			line_start = i + 1;
			len = 0;
		}
		len++;
		i++;
	}
	return (line_start);
}
