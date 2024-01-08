/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bootjan <bootjan@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/01 22:10:00 by bootjan       #+#    #+#                 */
/*   Updated: 2024/01/08 17:31:57 by bschaafs      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **load_map(void)
{
	int fd = open("maps/test.cub", O_RDONLY);
	if (fd == -1)
		return (NULL);
	char **map = ft_calloc(15, sizeof(char *));
	if (!map)
		return (close(fd), NULL);
	for (int i = 0; i < 14; i++)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (ft_free_2d_array((void ***)&map), close(fd), NULL);
	}
	close(fd);
	return (map);
}

t_root *init_root(t_scene *scene)
{
	t_root *root;

	(void) scene;
	root = ft_calloc(1, sizeof(t_root));
	if (!root)
		return (NULL);
	root->map = load_map();
	if (!root->map)
		return (free(root), NULL);
	root->rgb_ceil[0] = 204;
	root->rgb_ceil[1] = 153;
	root->rgb_ceil[2] = 255;
	root->rgb_floor[0] = 52;
	root->rgb_floor[1] = 154;
	root->rgb_floor[2] = 237;
	root->no_path = PATH1;
	root->ea_path = PATH2;
	root->so_path = PATH3;
	root->we_path = PATH4;
	root->pos_x = 7;
	root->pos_y = 10;
	root->dir = 'E';
	return (root);
}

size_t file_to_list(int fd, t_list **list)
{
	char buffer[BUFFER_SIZE + 1];
	ssize_t read_return = 0;
	size_t total_read = 0;
	t_list *new = NULL;

	while (1)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
			system_error_and_exit("get_next_line");
		if (read_return == 0)
			break;
		total_read += read_return;
		buffer[read_return] = '\0';
		new = ft_lstnew(buffer);
		if (!new)
			system_error_and_exit("malloc");
		ft_lstadd_back(list, new);
	}
	return (total_read);
}

void chunks_to_line(t_list *chunks, char *line)
{
	size_t chunk_size = 0;
	char *chunk = NULL;
	while (chunks)
	{
		chunk = chunks->content;
		chunk_size = ft_strlen(chunk);
		ft_strlcat(line, chunk, chunk_size);
		chunks = chunks->next;
	}
}

char *chunk_file_into_line(int fd)
{
	t_list *chunks = NULL;
	char *line = NULL;
	size_t line_size = 0;

	line_size = file_to_list(fd, &chunks);
	line = ft_calloc(line_size + 1, sizeof(char));
	if (!line)
		system_error_and_exit("calloc in chunk_file_into_line");
	chunks_to_line(chunks, line);
	printf("%s", line);
	return (line);
}

t_scene load_scene_from_file(char *file_path)
{
	t_scene scene;

	int fd = open(file_path, O_RDONLY);
	if (fd == -1)
		system_error_and_exit("open");
	chunk_file_into_line(fd);
	ft_bzero(&scene, sizeof(t_scene));
	return (scene);
}
void run_game(t_scene *scene)
{
	t_root *root = init_root(scene);
	if (!root)
		system_error_and_exit("Root initialization");
	root = init_mlx(root);
	if (!root)
		system_error_and_exit("mlx initialization");
	t_info *info = init_info(root);
	if (!info)
		system_error_and_exit("Root initialization");
	root->info = info;
	t_raycast *raycast = ft_calloc(1, sizeof(t_raycast));
	if (!raycast)
		system_error_and_exit("raycast initialization");
	root->raycast = raycast;
	t_line line;
	ft_bzero(&line, sizeof(t_line));
	mlx_loop_hook(root->window, generate_view, (void *)root);
	mlx_loop_hook(root->window, move_player, (void *)root);
	mlx_loop(root->window);
	mlx_terminate(root->window);
	free_root(&root);
}

int main(int argc, char *argv[])
{
	t_scene scene;
	if (argc != 2)
		user_error_and_exit("Not enough arguments");
	scene = load_scene_from_file(argv[1]);
	run_game(&scene);
	return (EXIT_SUCCESS);
}
