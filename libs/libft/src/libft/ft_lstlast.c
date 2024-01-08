#include "list.h"
<<<<<<< HEAD
=======
#include <stdlib.h>
>>>>>>> origin/parsing

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
