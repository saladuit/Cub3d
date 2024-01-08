/* ************************************************************************** */
/*                                                                            */
/*                                                   .--.  _                  */
/*  list.h                                          |o_o || |                 */
/*                                                  |:_/ || |_ _   ___  __    */
/*  By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    */
/*                                                (|     | )|_| |_| |>  <     */
/*  Created: 08/01/2024 12:51:53 PM by safoh     /'\_   _/`\__|\__,_/_/\_\    */
/*  Updated: 08/01/2024 12:51:53 PM by safoh     \___)=(___/                  */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content);
t_list *ft_lstlast(t_list *lst);

void ft_lstadd_back(t_list **alst, t_list *new);

void ft_lstclear(t_list **lst, void (*del)(void *));
