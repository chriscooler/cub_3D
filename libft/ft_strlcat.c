#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n;

	i = 0;
	j = 0;
	n = ft_strlen(dest);
	while (dest[i] && i < dstsize)
		i++;
	if (i == dstsize)
		return (i + ft_strlen(src));
	while (i < (dstsize - 1) && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (n + ft_strlen(src));
}
