/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:51:47 by bootjan           #+#    #+#             */
/*   Updated: 08/01/2024 04:12:59 PM bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_free_str_table(char ***str_table)
{
	int i;

	if (!str_table || !*str_table)
		return;
	i = 0;
	while ((*str_table)[i])
		free((*str_table)[i++]);
	free(*str_table);
	*str_table = NULL;
}
