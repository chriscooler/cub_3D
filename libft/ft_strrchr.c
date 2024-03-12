#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = -1;
	last = NULL;
	while (s[++i])
		if (s[i] == (char)c)
			last = ((char *)s) + i;
	if (s[i] == (char)c)
		last = ((char *)s) + i;
	return (last);
}
