/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 01:07:37 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/08 11:23:02 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void convert_pixels(uint8_t *pixels, int *new_pixels)
{
	int i;

	i = 0;
	while (i < TEX_SIZE * TEX_SIZE)
	{
		new_pixels[i] = compute_color(pixels[4 * i], pixels[4 * i + 1],
									  pixels[4 * i + 2], pixels[4 * i + 3]);
		i++;
	}
}

static mlx_image_t *load_image(mlx_t *window, const char *path)
{
	mlx_texture_t *texture;
	mlx_image_t *image;

	texture = mlx_load_png(path);
	if (!texture)
		user_error_and_exit("mlx_load_png failed in load_image");
	image = mlx_texture_to_image(window, texture);
	mlx_delete_texture(texture);
	if (!image)
		user_error_and_exit("mlx_load_png failed in load_image");
	if (!mlx_resize_image(image, TEX_SIZE, TEX_SIZE))
		user_error_and_exit("mlx_load_png failed in load_image");
	return (image);
}

void load_pixels(mlx_t *window, const char *path, int *texture)
{
	mlx_image_t *image;

	image = load_image(window, path);
	convert_pixels(image->pixels, texture);
}

int load_textures(t_root *root)
{
	int error_flag;

	error_flag = 0;
	load_pixels(root->window, root->no_path, root->no_texture);
	load_pixels(root->window, root->so_path, root->so_texture);
	load_pixels(root->window, root->ea_path, root->ea_texture);
	load_pixels(root->window, root->we_path, root->we_texture);
	return (error_flag);
}

void init_mlx(t_root *root)
{
	int image_index;

	root->window = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D...", true);
	if (!root->window)
		system_error_and_exit("mlx_init in init_mlx");
	if (load_textures(root) != 0)
		system_error_and_exit("load_textures in init_mlx");
	root->image = mlx_new_image(root->window, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!root->image)
		system_error_and_exit("mlx_new_image in init_mlx");
	image_index = mlx_image_to_window(root->window, root->image, 0, 0);
	if (image_index == -1)
		system_error_and_exit("mlx_image_to_window in init_mlx");
	root->color_ceil = compute_color_rgb(root->rgb_ceil);
	root->color_floor = compute_color_rgb(root->rgb_floor);
}
