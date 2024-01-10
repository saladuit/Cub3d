/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_error_and_exit.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bschaafs <bschaafs@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 13:46:38 by bschaafs      #+#    #+#                 */
/*   Updated: 2024/01/10 13:52:32 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void free_textures(t_root *root)
{
	if (root->no_texture)
		free(root->no_texture);
	if (root->ea_texture)
		free(root->ea_texture);
	if (root->so_texture)
		free(root->so_texture);
	if (root->we_texture)
		free(root->we_texture);
}

void free_root(t_root *root)
{
	if (root->info)
		free(root->info);
	root->info = NULL;
	if (root->raycast)
		free(root->raycast);
	root->raycast = NULL;
	if (root->window)
		mlx_terminate(root->window);
	free_textures(root);
}

void	game_error_and_exit(t_root *root, const char *err_msg)
{
	free_root(root);
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
}
