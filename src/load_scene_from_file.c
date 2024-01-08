/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  load_scene_from_file.c                          |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 08/01/2024 01:47:11 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 08/01/2024 02:57:00 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void string_to_scene(char *string, t_scene *scene)
{
	size_t i = 0;
	size_t line_start = 0;
	size_t len = 0;

	while (string[i])
	{
		if (string[i] == '\n')
		{
			char *line = ft_substr(string, line_start, len);
			line_to_scene_value(scene, line);
			free(line);
			line_start = i + 1;
			len = 0;
		}
		len++;
		i++;
	}
}

t_scene load_scene_from_file(char *file_path)
{
	t_scene scene;
	char *string;

	int fd = open(file_path, O_RDONLY);
	if (fd == -1)
		system_error_and_exit("open in load_scene_from_file");
	string = chunk_file_to_string(fd);
	close(fd);
	ft_bzero(&scene, sizeof(t_scene));
	string_to_scene(string, &scene);
	return (scene);
}
