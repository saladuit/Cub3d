/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  chunk_file_into_line.c                          |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 08/01/2024 01:44:56 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 08/01/2024 01:44:56 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *chunk_file_to_string(int fd)
{
	t_list *chunks = NULL;
	char *string = NULL;
	size_t size = 0;

	size = file_to_list(fd, &chunks);
	string = list_to_string(chunks, size);
	printf("%s", string);
	ft_lstclear(&chunks, free);
	return (string);
}
