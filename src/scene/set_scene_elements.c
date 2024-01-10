#include "error.h"
#include "libft.h"
#include "scene.h"

static bool	is_setting(const char *str)
{
	if (ft_strncmp(str, "SO", 2) == 0)
		return (true);
	if (ft_strncmp(str, "NO", 2) == 0)
		return (true);
	if (ft_strncmp(str, "WE", 2) == 0)
		return (true);
	if (ft_strncmp(str, "EA", 2) == 0)
		return (true);
	if (ft_strncmp(str, "C", 1) == 0)
		return (true);
	if (ft_strncmp(str, "F", 1) == 0)
		return (true);
	return (false);
}

static bool create_scene_element_attempt(char *string, t_scene *scene,
										 size_t line_start, size_t len)
{
	char *line;

	if (line_start != 0)
		len--;
	line = ft_substr(string, line_start, len);
	if (!line)
		system_error_and_exit("ft_substr in string_to_scene");
	if (line[0] == ' ' || line[0] == '1' || is_setting(line) == false)
		return false;
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
			else if (string[line_start] == ' ' ||
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
