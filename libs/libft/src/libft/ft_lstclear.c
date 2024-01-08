#include "list.h"
<<<<<<< HEAD
=======
#include <stdlib.h>
>>>>>>> origin/parsing

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next;
	if (!lst || !del)
		return;
	while (*lst)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next;
	}
}
