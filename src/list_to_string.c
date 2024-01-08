/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  list_to_string.c                                |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 08/01/2024 01:46:23 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 08/01/2024 01:46:27 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *list_to_string(t_list *lst, size_t size)
{
	size_t chunk_size = 0;
	char *chunk = NULL;
	char *string = NULL;

	string = ft_calloc(size + 1, sizeof(char));
	if (!string)
		system_error_and_exit("calloc in list_to_string");
	while (lst)
	{
		chunk = lst->content;
		chunk_size = ft_strlen(chunk);
		ft_strlcat(string, chunk, chunk_size);
		lst = lst->next;
	}
	return (string);
}
