#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ret;

	ret = (unsigned char *) dest;
	if (!dest && !src)
		return (NULL);
	while (n--)
		ret[n] = ((unsigned char *)src)[n];
	return (dest);
}
