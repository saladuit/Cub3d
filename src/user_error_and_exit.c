/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  user_error_and_exit.c                           |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 08/01/2024 12:48:22 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 08/01/2024 12:48:23 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void user_error_and_exit(const char *message)
{
	printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}
