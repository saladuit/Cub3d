/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:10:00 by bootjan           #+#    #+#             */
/*   Updated: 08/01/2024 04:03:30 PM bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_root init_root(void)
{
	t_root root;

	root.map = NULL;
	root.rgb_ceil[0] = 204;
	root.rgb_ceil[1] = 153;
	root.rgb_ceil[2] = 255;
	root.rgb_floor[0] = 52;
	root.rgb_floor[1] = 154;
	root.rgb_floor[2] = 237;
	root.no_path = PATH1;
	root.ea_path = PATH2;
	root.so_path = PATH3;
	root.we_path = PATH4;
	root.pos_x = 12;
	root.pos_y = 12;
	root.dir = 'E';
	return (root);
}

void run_game(void)
{
	t_root root = init_root();
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
	scene = load_scene_from_file(argv[1]);
	(void)scene;
	// run_game();
	return (EXIT_SUCCESS);
}
