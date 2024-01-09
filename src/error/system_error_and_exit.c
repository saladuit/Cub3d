/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  system_error_and_exit.c                         |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 08/01/2024 12:45:19 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 08/01/2024 03:19:37 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void system_error_and_exit(const char *function_name)
{
	perror(function_name);
	exit(EXIT_FAILURE);
}
