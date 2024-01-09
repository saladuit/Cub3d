/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/01 22:10:00 by bootjan       #+#    #+#                 */
/*   Updated: 09/01/2024 05:31:42 PM bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "scene.h"

void run_game(t_scene *scene)
{
	t_root root = init_root(scene);
	init_mlx(&root);
	t_info *info = init_info(&root);
	if (!info)
		system_error_and_exit("Root initialization");
	root.info = info;
	root.raycast = ft_calloc(1, sizeof(t_raycast));
	if (!root.raycast)
		system_error_and_exit("Root initialization");
	t_line line;
	ft_bzero(&line, sizeof(t_line));
	mlx_loop_hook(root.window, generate_view, (void *)&root);
	mlx_loop_hook(root.window, move_player, (void *)&root);
	mlx_loop(root.window);
	mlx_terminate(root.window);
	free_root(&root);
}

int main(int argc, char *argv[])
{
	t_scene scene;

	if (argc != 2)
		user_error_and_exit("Not enough arguments");
	if (!is_cub_file(argv[1]))
		user_error_and_exit("Not a .cub file");
	scene = load_scene_from_file(argv[1]);
	print_scene(&scene); // INFO:
	run_game(&scene);
	scene_clear(&scene);
	return (EXIT_SUCCESS);
}
