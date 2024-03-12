#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	if (!start)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		curr = ft_lstnew(f(lst->content));
		if (!curr)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, curr);
		lst = lst->next;
	}
	return (start);
}
