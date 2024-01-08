/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  load_scene_from_file.c                          |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 08/01/2024 01:47:11 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 08/01/2024 07:03:05 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void string_to_scene(char *string, t_scene *scene)
{
	size_t i = 0;
	size_t line_start = 0;
	size_t len = 0;
	char *line;

	while (string[i])
	{
		if (string[i] == '\n')
		{
			if (len == 1)
			{
				len = 0;
				line_start++;
				i++;
				continue;
			}
			if (string[i + 1] == ' ')
				break;
			if (string[len - 1] == '\n')
				len--;
			line = ft_substr(string, line_start, len);
			if (!line)
				system_error_and_exit("ft_substr in string_to_scene");
			printf("line: %s\n", line);
			if (line_to_scene_value(scene, line) == false)
			{
				free(line);
				break;
			}
			free(line);
			line_start = i + 1;
			len = 0;
		}
		len++;
		i++;
	}
	scene->map = ft_split(string + line_start, "\n");
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
	print_scene(&scene);
	return (scene);
}
