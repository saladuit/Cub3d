/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  load_scene_from_file.c                          |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 08/01/2024 01:47:11 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 09/01/2024 05:11:12 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	set_default_scene(&scene);
	string_to_scene(string, &scene);
	// print_scene(&scene); //DEBUG
	return (scene);
}
