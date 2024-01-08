#include "list.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;
	if (!alst || !new)
		return;
	if (!*alst)
		*alst = new;
	else
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
}
