#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*e;

	e = (t_list *)malloc(sizeof(t_list));
	if (!e)
		return (NULL);
	e->content = content;
	e->next = NULL;
	return (e);
}
