

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	size_t	i;

	s = (char *)malloc(sizeof(*str) * (ft_strlen(str) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = 0;
	return (s);
}
