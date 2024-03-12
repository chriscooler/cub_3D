#include "libft.h"

void	ft_freepp(void **pp)
{
	size_t	i;

	i = -1;
	while (((char **)pp)[++i] != NULL)
		free(pp[i]);
	free(pp);
}
