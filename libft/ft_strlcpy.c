#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	ss;

	ss = 0;
	while (src[ss])
		ss++;
	if (ss + 1 < dstsize)
	{
		i = -1;
		while (++i < ss + 1)
			dest[i] = src[i];
	}
	else if (dstsize)
	{
		i = -1;
		while (++i < dstsize - 1)
			dest[i] = src[i];
		dest[i] = '\0';
	}	
	return (ss);
}
