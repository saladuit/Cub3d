/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  file_to_list.c                                  |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 08/01/2024 01:33:22 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 08/01/2024 04:56:23 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t file_to_list(int fd, t_list **list)
{
	char buffer[BUFFER_SIZE + 1];
	ssize_t read_return = 0;
	size_t total_read = 0;
	t_list *new = NULL;
	char *tmp = NULL;

	while (1)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return == -1)
			system_error_and_exit("get_next_line");
		if (read_return == 0)
			break;
		total_read += read_return;
		buffer[read_return] = '\0';
		tmp = ft_strdup(buffer);
		if (!tmp)
			system_error_and_exit("ft_strdup in file_to_list");
		new = ft_lstnew(tmp);
		if (!new)
			system_error_and_exit("ft_lstnew in file_to_list");
		ft_lstadd_back(list, new);
	}
	return (total_read);
}
