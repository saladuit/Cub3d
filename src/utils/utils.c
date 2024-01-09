/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/06 15:57:25 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/09 12:13:41 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void free_root(t_root *root)
{
	if (root->info)
		free(root->info);
	root->info = NULL;
	if (root->raycast)
		free(root->raycast);
	root->raycast = NULL;
	ft_free_str_table(&root->map);
}

uint32_t compute_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t compute_color_rgb(uint32_t rgb[3])
{
	return (compute_color(rgb[0], rgb[1], rgb[2], 255));
}

double ft_abs_double(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

bool valid_move(char **map, t_info *info, double y_plus, double x_plus)
{
	return (map[(int)(info->pos_y + y_plus)][(int)(info->pos_x + x_plus)] !=
			'1');
}
